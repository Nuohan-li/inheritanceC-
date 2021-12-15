#include <iostream>
class Entity;

class Living_things;
class Enemy;
class Slime;
class Skeleton;

class Hero;

class Weapon;

// 1. child's member variables can be initialized using parent's constructor. See Slime class

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Entity class
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Entity{
    public:
        Entity();
        virtual ~Entity();
        
        
    protected:
       
};

Entity::Entity()
{

}

Entity::~Entity(){

}

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Living_things class
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Living_things : public Entity{
    public:
        Living_things(int hp, int atk, int def);
        virtual ~Living_things();
        virtual void move(int x, int y);
        int get_x();
        int get_y();
        void set_x(int x1); 
        void set_y(int y1);
        virtual int get_hp();
        virtual int get_atk();
        virtual int get_def();

    protected:
        int x;
        int y;
        int atk;
        int hp;
        int def;
};

Living_things::Living_things(int hp, int atk, int def):
Entity{}, x{0}, y{0}, hp{hp}, atk{atk}, def{def}{
    
}

int Living_things::get_x(){
    return x;
}
int Living_things::get_y(){
    return y;
}
void Living_things::set_x(int x1){
    x = x1;
}
void Living_things::set_y(int y1){
    y = y1;
}
void Living_things::move(int x1, int y1){
    x += x1;
    y += y1;
}
Living_things::~Living_things(){

}
int Living_things::get_atk(){
    return atk;
}
int Living_things::get_def(){
    return def;
}
int Living_things::get_hp(){
    return hp;
}


  ////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Enemy class
///////////////////////////////////////////////////////////////////////////////////////////////////////// 

class Enemy : public Living_things{
    public:
        Enemy(std::string name, int hp, int atk, int def);
        virtual ~Enemy();
        virtual std::string get_type();
    private:
        std::string enemy_type;
};
Enemy::Enemy(std::string type, int hp, int atk, int def):
Living_things{hp, atk, def},
enemy_type{type}{

}
Enemy::~Enemy(){

}

std::string Enemy::get_type(){
    return enemy_type;
}

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Slime class
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Slime : public Enemy{
    public:
        Slime(std::string type, std::string name, int hp, int atk, int def);
        void print_stats();
        std::string get_name();
    private:
        std::string name;
};

// since the child needs to call the parent's contructor, slime's name can be initialized using parent's constructor
Slime::Slime(std::string type, std::string name, int hp, int atk, int def):
Enemy{type, hp, atk, def}, name{name}{

}
std::string Slime::get_name(){
    return name;
}
// get_type is from parent class Enemy, get_atk, def, hp ... from grandparent class Living_things
void Slime::print_stats(){
    std::cout << "enemy type: " << get_type() <<std::endl;
    std::cout << "enemy name: " << get_name() <<std::endl;
    std::cout << "atk: " << get_atk() <<std::endl;
    std::cout << "def: " << get_def() <<std::endl;
    std::cout << "hp: " << get_hp() <<std::endl;
    std::cout << "x: " << get_x() <<std::endl;
    std::cout << "y: " << get_y() <<std::endl;
}

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Skeleton class
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Skeleton : public Enemy{
    public:
        Skeleton(std::string type, std::string name, int hp, int atk, int def);
        std::string get_type() override;
        std::string get_name();
        void print_stats();
    private:
        std::string name;
        std::string type;
};

Skeleton::Skeleton(std::string type, std::string name, int hp, int atk, int def):
Enemy{type, hp, atk, def}, name{name}{

}

// overriden get_type from enemy class so it will always print yellow skeleton no matter what type is assigned when a skeleton object is created
std::string Skeleton::get_type(){
    return "yellow skeleton"; 
}

std::string Skeleton::get_name(){
    return name;
}
// get_type is from parent class Enemy, get_atk, def, hp ... from grandparent class Living_things
void Skeleton::print_stats(){
    std::cout << "enemy type: " << get_type() <<std::endl;
    std::cout << "enemy name: " << get_name() <<std::endl;
    std::cout << "atk: " << get_atk() <<std::endl;
    std::cout << "def: " << get_def() <<std::endl;
    std::cout << "hp: " << get_hp() <<std::endl;
    std::cout << "x: " << get_x() <<std::endl;
    std::cout << "y: " << get_y() <<std::endl;
}

int main(){
    Slime slime { "Slime", "yellow slime", 10, 2, 3};

    slime.print_stats();
    slime.move(9, 9);
    std::cout << "after moving" << std::endl;
    slime.print_stats();

    Skeleton Skeleton{"Skeleton", "sk1", 20, 3, 4};
    Skeleton.print_stats();
    return 0;
}

