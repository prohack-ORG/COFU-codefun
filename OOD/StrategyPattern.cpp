/***
 * Design Pattern 1 : Strategy
 * Date : 27th Feb 2020
 ***/

#include <iostream>
#include <stdio.h>
#include <string>

#define STRATEGY

using namespace std;

#ifndef STRATEGY

class Animal {
    public:
        virtual string getSound() {
            return "Barks";
        }
        virtual string getMovement()
        {
            return "Runs";
        }
        virtual string getEats()
        {
            return "Meat";
        }
};

class Dog: public Animal{
};

class Bird: public Animal{
  public:
    string getMovement() {
        return "Flys";
    }
    string getSound() {
        return "Chirps";
    }
};

class Fish: public Animal {
  public:
    string getMovement() {
        return "Swims";
    }
    string getSound() {
        return "does not speak";
    }
};

class ToyAnimal1: public Animal {
    public:
      string getMovement() {
          return "does not move";
      }
      //code duplication
      string getSound() {
          return "does not speak";
      }
      string getEats() {
          return "does not eat";
      }
};

class ToyAnimal2 : public Animal
{
  public:
    string getMovement() {
        return "Swims";
    }
    //code duplication
    string getSound() {
        return "Chirps";
    }
    //code duplication
    string getEats()
    {
        return "does not eat";
    }
};

#else   // ~STRATEGY

class SpeechBehaviour {
    public:
        virtual string getSpeakBehaviour() = 0;
};

class Bark : public SpeechBehaviour {
    public:
        string getSpeakBehaviour () {
            return "barks";
        }
};
class Chirp : public SpeechBehaviour {
    public:
        string getSpeakBehaviour () {
            return "chirps";
        }
};
class NoSound : public SpeechBehaviour {
    public:
        string getSpeakBehaviour () {
            return "does not speak";
        }
};

class MoveBehaviour {
    public:
        virtual string getMoveBehaviour() = 0;
};

class Run : public MoveBehaviour {
    public:
        string getMoveBehaviour () {
            return "runs";
        }
};
class Swim : public MoveBehaviour {
    public:
        string getMoveBehaviour () {
            return "swims";
        }
};
class Fly : public MoveBehaviour {
    public:
        string getMoveBehaviour () {
            return "flys";
        }
};
class NoMove : public MoveBehaviour {
    public:
        string getMoveBehaviour () {
            return "does not move";
        }
};

class EatBehaviour {
    public:
        virtual string getEatBehaviour() = 0;
};

class Meat : public EatBehaviour {
    public:
        string getEatBehaviour () {
            return "meat";
        }
};

class NoEat : public EatBehaviour {
    public:
        string getEatBehaviour () {
            return "does not eat";
        }
};

class Animal
{
  private:
    SpeechBehaviour *sound;
    MoveBehaviour *move;
    EatBehaviour *eat;

  public:
    //Dependency Injection
    void setSound(SpeechBehaviour *newSound) {
        sound = newSound;
    }
    void setMovement(MoveBehaviour *newMove) {
        move = newMove;
    }
    void setEats(EatBehaviour *newEat) {
        eat = newEat;
    }
    virtual string getSound() {
        return sound->getSpeakBehaviour();
    }
    virtual string getMovement() {
        return move->getMoveBehaviour();
    }
    virtual string getEats() {
        return eat->getEatBehaviour();
    }
};

class Dog : public Animal {
  public:
    Dog() {
        setSound(new Bark);
        setMovement(new Run);
        setEats(new Meat);
    }
};

class Bird : public Animal
{
  public:
    Bird() {
        setSound(new Chirp);
        setMovement(new Fly);
        setEats(new Meat);
    }
};

class Fish : public Animal
{
  public:
    Fish() {
        setSound(new NoSound);
        setMovement(new Swim);
        setEats(new Meat);
    }
};

class ToyAnimal1 : public Animal
{
  public:
    ToyAnimal1() {
        setSound(new NoSound);
        setMovement(new NoMove);
        setEats(new NoEat);
    }
};

class ToyAnimal2 : public Animal
{
  public:
    ToyAnimal2() {
        setSound(new Chirp);
        setMovement(new Swim);
        setEats(new NoEat);
    }
};
#endif  // ~STRATEGY

int main(){
    Animal *sparky = new Dog;
    cout << "sparky " << sparky->getSound() << endl;
    cout << "sparky " << sparky->getMovement() << endl;
    cout << "sparky " << sparky->getEats() << endl;

    Animal *tweety = new Bird;
    cout << "tweety " << tweety->getSound() << endl;
    cout << "tweety " << tweety->getMovement() << endl;
    cout << "tweety " << tweety->getEats() << endl;

    Animal *fishy = new Fish;
    cout << "fishy " << fishy->getSound() << endl;
    cout << "fishy " << fishy->getMovement() << endl;
    cout << "fishy " << fishy->getEats() << endl;

    Animal *toy1 = new ToyAnimal1;
    cout << "toy1 " << toy1->getSound() << endl;
    cout << "toy1 " << toy1->getMovement() << endl;
    cout << "toy1 " << toy1->getEats() << endl;

    Animal *toy2 = new ToyAnimal2;
    cout << "toy2 " << toy2->getSound() << endl;
    cout << "toy2 " << toy2->getMovement() << endl;
    cout << "toy2 " << toy2->getEats() << endl;

    return 0;
}