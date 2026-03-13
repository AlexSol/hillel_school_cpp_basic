#include <iostream>
#include <thread>
#include <string>


struct Config
{
    std::string name;
    std::string host; 
};


Config config;

void servece_1(const Config& config)
{
    config.host;
    std::cout << "Hello from service 1 thread! Thread id: " << std::this_thread::get_id() << "\n";
}

void servece_2(const Config& config)
{
    config.host;
    std::cout << "Hello from service 2 thread! Thread id: " << std::this_thread::get_id() << "\n";

    config.host = 'localhost';
}


int main() {

    // Config // load from file.

    std::string message = "Hello from main thread!";
    std::thread tr(servece_1, std::ref(config));
    std::thread tr2(servece_2, std::ref(config));

    tr.join();
    tr2.join();

    return 0;
}
