// unit4_2_Computer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};

class CPU {
private:
    CPU_Rank rank;
    int frequency;
    float voltage;
public:
    CPU(CPU_Rank r, int f, float  v) {
        rank = r;
        frequency = f;
        voltage = v;
    }
    ~CPU() { cout << "析构了一个CPU"<<endl; }
    CPU_Rank GetRank() const{ return rank; }
    int GetFrequency() const{ return frequency; }
    float GetVoltage() const{ return voltage; }

    void SetRank(CPU_Rank r) { rank = r; }
    void SetFrequency(int f) { frequency = f; }
    void SetVoltage(float v) { voltage = v; }

    void run() { cout << "CPU开始运行" << endl; }
    void stop() { cout << "CPU停止运行" << endl; }
};

enum RAM_Type{DDR4,DDR3,DDR2};

class RAM {
private:
    float size;
    RAM_Type type;
    float frequency;
public:
    RAM(float s, RAM_Type t, float f) {
        size = s;
        type = t;
        frequency = f;
    }
    ~RAM() { cout<<"析构了一个RAM"<<endl; }
     
    float GetSize()const { return size; }
    RAM_Type GetType()const { return type; }
    float GetFrequency()const { return frequency; }

    void SetSize(float s) { size = s; }
    void SetType(RAM_Type t) { type = t; }
    void SetFrequency(float f) { frequency = f; }

    void run() { cout<<"启动了RAM"<<endl; }
    void stop() { cout<<"关闭了RAM"<<endl; }
    
};

enum CDROM_Interface{SATA=1,USB};
enum CDROM_Install_Type{external,build_in};

class CD_ROM {
private:
    CDROM_Interface interface;
    int cache_size;
    CDROM_Install_Type type;
public:
    CD_ROM(CDROM_Interface i , int s, CDROM_Install_Type t) {
        interface = i;
        cache_size = s;
        type = t;
    }
    ~CD_ROM() { cout << "析构了一个CDROM" << endl; }
     
    CDROM_Interface GetInterface() { return interface; }
    int GetCacheSize() { return cache_size; }
    CDROM_Install_Type GetInstallType() { return type; }

    void SetInterface(CDROM_Interface i) { interface = i; }
    void SetCacheSize(int s) { cache_size = s; }
    void SetInstallType(CDROM_Install_Type t) { type = t; }

    void run() { cout<<"启动了CDROM"<<endl; }
    void stop() { cout << "关闭了CDROM" << endl; }

};

class COMPUTER {
private:
    CPU my_cpu;
    RAM my_ram;
    CD_ROM my_cdrom;
    unsigned int storage;
    unsigned int bandwidth;
public:
    COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b);
    ~COMPUTER() { cout << "析构了一个COMPUTER" << endl; }

    void run() {
        my_cpu.run();
        my_ram.run();
        my_cdrom.run();
        cout << "computer开始运行" << endl;
    }
    void stop() {
        my_cpu.stop();
        my_ram.stop();
        my_cdrom.stop();
        cout << "computer停止运行" << endl;
    }

};
COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b) :my_cpu(c), my_ram(r), my_cdrom(cd) {
    storage = s;
    bandwidth = b;
    cout << "构造了一个COMPUTER" << endl;
}
;



int main()
{
    CPU a(P6, 300, 2.8);
    a.run();
    a.stop();
    cout << "*************************" << endl;

    RAM b(8,DDR3, 1600);
    b.run();
    b.stop();
    cout << "*************************" << endl;

    CD_ROM c(SATA, 2, build_in);
    c.run();
    c.stop();
    cout << "*************************" << endl;

    COMPUTER my_computer(a, b, c, 128, 10);
    cout << "*************************" << endl;
    my_computer.run();
    my_computer.stop();
    cout << "*************************" << endl;
    return 0;


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
