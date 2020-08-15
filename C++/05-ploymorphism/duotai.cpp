#include <iostream>
#include <string.h>

using namespace std;

#define Print(Var) Var.print(#Var)

class Bug {
public:
    string n;
    int nlegs;
    int ncolor;
    Bug(string name, int legs, int color);
    virtual void attribute(Bug b);
    virtual void print(string name) {
        cout <<  name << "是个苯虫子" << endl;
    }
};

Bug::Bug(string name, int legs, int color):n(name), nlegs(legs),ncolor(color){
    cout << "父类构造函数" << endl;
}

void Bug::attribute(Bug b) {
    cout << &b.n << " legs : " << nlegs << "; color : " << ncolor << endl;
}

class FlyBug : public Bug {
public:
    int nwings;
    FlyBug(string name, int legs, int color, int wings);
// private:
    virtual void attribute(Bug b);
    virtual void print(string name) {
        cout << name << "会飞，别人都不会" << endl;
    }
};

FlyBug::FlyBug(string name, int legs, int color, int wings): Bug(name, legs, color) {
    cout << "子类构造函数" << endl;
    nwings = wings;
}

void FlyBug::attribute(Bug b) {
    Bug::attribute(b);     /* 继承父类属性 */
    cout << "wings : " << nwings << endl;
}

class WaterBug : public Bug {
public:
    int nfins;
    WaterBug(string name, int legs, int color, int fins);
// private:
    virtual void attribute(Bug b);
    virtual void print(string name) {
        cout <<  name << "能在水里游，别人会淹死" << endl;
    }
};

WaterBug::WaterBug(string name, int legs, int color, int fins):Bug(name, legs, color) {
    cout << "子类构造函数" << endl;
    nfins = fins;
}

void WaterBug::attribute(Bug b) {
    Bug::attribute(b);     /* 继承父类属性 */
    cout << "fins : " << nfins << endl;
}

int main()
{
    Bug scorpion("scorpion",1,2);
    FlyBug fly("fly",123,456,789);
    WaterBug fish("fish",12,34,56);

    Print(scorpion);
    printf("1---------\n\n");
    Print(fly);
    printf("2---------\n\n");
    Print(fish);
    printf("3---------\n\n");

    Bug smallbug(fly);      /* 可用派生类对基类初始化 */
    Print(smallbug);
    printf("4---------\n\n");

    Bug *bigbug;
    bigbug = &fish;      /* 派生类地址可赋给基类指针 */
    bigbug->print("bigbug");
    printf("5---------\n\n");

    /* 多态 1 */
    WaterBug *small_fish;
    small_fish = &fish;

    FlyBug *small_fly = &fly;

    int israining;
    cout << "今天下雨了吗？（0：没下；！0：下雨）" << endl;
    while(cin >> israining) {
        if (!israining) {
            bigbug = small_fly;
            bigbug->print("small_fly");
        } else {
            bigbug = small_fish;
            bigbug->print("small_fish");
        }
    }

    /* 多态 2 */
    WaterBug big_fish(fish);
    big_fish.n = "big_fish";
    FlyBug big_fly(fly);
    big_fly.n = "big_fly";
    Bug big_bug(big_fish);
    big_bug.n = "big_bug";

    big_fly.attribute(big_fly);      /* 实参类型不同，但形参相同*/
    big_fly.attribute(big_fish);     /* 实参类型不同，但形参相同*/
}
