#ifndef __CONDITION_VAR_EXAMPLE_H__
#define __CONDITION_VAR_EXAMPLE_H__


#include <mutex>
#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include <condition_variable>

class condition_var_example{
public:
    std::mutex m;
    bool ready = false;
    std::condition_variable cond_var;
    void threadWork(){
        std::cout << "  thread work wait\n";
        
        std::unique_lock<std::mutex> lock(m);
        cond_var.wait(lock, [&](){return ready;});

        for(int i = 2; i >= 0; --i){
            std::cout << "  thread working in second " << i+1 << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout << "  thread work finished !\n";

        std::cout << "  notify one for \"second work\" in ThreadWork() !\n";
        cond_var.notify_one();
    }
    static void ThreadEntry(void *user_data){
        reinterpret_cast<condition_var_example*>(user_data)->threadWork(); 
    }
    void assignWork(){
        std::cout << "  assign detach thread work\n";

        std::thread(condition_var_example::ThreadEntry, this).detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    void second_work(){
        std::cout << "  \"second work\" is waitting for notify by threadWork!\n";
        
        std::unique_lock<std::mutex> lock(m);
        cond_var.wait(lock, [&](){return ready;});

        std::cout << "  second work running and done !\n\n";
    }
    void set_ready_to_work(bool is_ready){
        ready = is_ready;
    }

    void notify(){
        cond_var.notify_one();
    }

    void run(){
        
        std::cout << "---- this is thread work by condition_variable ---\n";
        assignWork();

        std::cout << "  set ready and notify it!\n";
        set_ready_to_work(true);
        notify();

        second_work();
    }

    static condition_var_example& getins(){
        static condition_var_example instance;
        return instance;
    }
};


#endif
