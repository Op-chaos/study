#include <iostream>
#include <string.h>

using namespace std;

/* 多态 2 */
class Character{
public:
    string name;
    int blood;
    int hurt;
    virtual void attack(Character &cc);
    Character(string n, int b, int h):name(n),blood(b),hurt(h) {}
};

class Human: public Character{
public:
    virtual void attack(Character & cc);
    Human(string n, int b, int h):Character(n,b,h){}
};

class Dog: public Character{
public:
    virtual void attack(Character & cc);
    Dog(string n, int b, int h):Character(n,b,h){}
};

class Tiger: public Character{
    public:
    void attack(Character & cc);
    Tiger(string n, int b, int h);
};

void Character::attack(Character  & cc)
{
    cout<<name<<"对"<<cc.name<<"发动攻击"<<endl;
    cc.blood = cc.blood - hurt;
    cout<<cc.name<<"剩余血量："<<cc.blood<<endl;
}

Tiger::Tiger(string n, int b, int h):Character(n,b,h){}

void Human::attack(Character & cc)
{
    cout<<"人类中的";
    cout<<name<<"对"<<cc.name<<"发动攻击"<<endl;
    cc.blood = cc.blood - hurt;
    cout<<cc.name<<"剩余血量："<<cc.blood<<endl;
}

void Dog::attack(Character & cc)
{
    cout<<"狗中的";
    Character::attack(cc);
}

void Tiger::attack(Character & cc)
{
    cout<<"老虎中的";
    Character::attack(cc);
}

int main()
{
    Character *c;
    Human xiaoming("xiaoming", 100, 5);
    Dog hei("hei", 70, 20);
    Tiger bigcat("bigcat", 150, 50);

    bigcat.attack(xiaoming);

    return 0;
}