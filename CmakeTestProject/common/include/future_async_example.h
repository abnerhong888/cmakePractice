#ifndef __FUTURE_ASYNC_EXAMPLE_H__
#define __FUTURE_ASYNC_EXAMPLE_H__


#include <exception>
#include <mutex>
#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include <vector>

class future_async_apply{
public:
    int totalFileSize = 1000000;
    int chunkSize = 100000;
    std::vector<char> fileData = std::vector<char>(totalFileSize);
    std::mutex fileMutex; 
    
    int downloadChunk(int startIndex) {
        // Simulate downloading a chunk of data from the internet
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        std::lock_guard<std::mutex> lock(fileMutex);
        for (int i = 0; i < chunkSize; ++i) {
            fileData[startIndex + i] = 'X'; // Mark downloaded part
        }

        std::cout << "\n  Downloaded block: " << startIndex <<"-"<< startIndex+chunkSize << std::endl;

        return (startIndex+chunkSize);
    }
    void downloadAndWait() {
        std::cout << "  Downloading File.....\n";

        std::vector<std::future<int>> downloadTasks;

        for(int i = 0; i < totalFileSize; i += chunkSize){
            downloadTasks.push_back(std::async(std::launch::async, downloadChunk, this, i));
        }

        for(auto& task : downloadTasks){
            task.wait();
        }
        
        std::cout << "  File downloaded.\n";

        bool isComplete = true;
        for(auto& c : fileData){
            if(c != 'X'){
                isComplete = false;
                break;
            }
        }

        std::cout << "\n  Download " << (isComplete ? " Successed\n\n" : " Failed\n\n");
    }

    void downloadNonBlocking(){
        std::cout << "  Downloading File.....\n";

        std::vector<std::future<int>> downloadTasks;

        for(int i = 0; i < totalFileSize; i += chunkSize){
            downloadTasks.push_back(std::async(std::launch::async, downloadChunk, this, i));
        }
        
        while(!downloadTasks.empty()){
            std::cout << "  loopBegin[";
            std::vector<std::future<int>>::iterator task = downloadTasks.begin();
            
            while(task != downloadTasks.end()){
                std::future_status status = task->wait_for(std::chrono::milliseconds(1));
                if(status == std::future_status::timeout){
                    std::cout << ".";
                    ++task;
                }else{
                    try{
                        std::cout << "  Download file chunk end pos = " << task->get() << "\n";
                    }catch(const std::exception& e){
                        std::cout << "  EXCEPTION: " << e.what() << "\n";
                    }
                    task = downloadTasks.erase(task);
                }
            }
            std::cout << "] loop end" << std::endl;
        }
        std::cout << "  File downloaded.\n";

        bool isComplete = true;
        for(auto& c : fileData){
            if(c != 'X'){
                isComplete = false;
                break;
            }
        }

        std::cout << "\n  Download " << (isComplete ? " Successed\n\n" : " Failed\n\n");

    }
    void run(){
        downloadAndWait();
        downloadNonBlocking();
    }

    static future_async_apply& getins(){
        static future_async_apply instance;
        return instance;
    }
};

class future_async_example{
public:
    std::atomic<int> number;
    void ThreadWork(){
        std::cout << "  thread number = " << number++ << "\n";
        for(int i = 2; i >= 0; --i){
            std::cout << "  thread working in second " << i+1 << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout << "  thread work finished !\n";
    }

    std::future<void> assignWork(){
        std::cout << "  assing async thread work\n";
        
        
        return std::async(std::launch::deferred, ThreadWork, this);

    }

    void second_work(){

        std::cout << "  second work running and done !\n\n";
    }

    void run(){
        std::cout << "---- this is thread work by future async ---\n";
        
        auto v0 = std::async(std::launch::async, ThreadWork, this);
        v0.wait();
        auto v1 = assignWork();
        auto v2 = assignWork();
        std::cout << "  \"second work\" is waitting for notify by threadWork!\n";
        v1.get();
        v2.get();
        second_work();
    }

    static future_async_example& getins(){
        static future_async_example instance;
        return instance;
    }
};






#endif
