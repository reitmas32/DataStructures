/**
  * @file    Pair.hpp
  * @version 1.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API de parejas de le mismo tipo de dato
  */

#ifndef PAIR_PAIR_HPP
#define PAIR_PAIR_HPP

template <class Item>
class Pair {
private:
    Item one;
    Item two;
public:

    //Constructor
    Pair(Item one, Item two) : one(one), two(two) {}

    //Destructor
    virtual ~Pair() {free(this);}

    //Getters
    Item getOne() const {return one;}
    Item getTwo() const {return two;}

    //Setters
    void setOne(Item _one) {one = _one;}
    void setTwo(Item _two) {two = _two;}

    void Change(){
        Item tmp;
        tmp = getOne();
        setOne(getTwo());
        setTwo(tmp);
    }

    Item Higher(bool (*cmp)(Item,Item)){
        if(cmp(getOne(),getTwo())){
            return getOne();
        }
        else{
            return getTwo();
        }
    }

    Item Less(bool (*cmp)(Item,Item)){
        if(!cmp(getOne(),getTwo())){
            return getOne();
        }
        else{
            return getTwo();
        }
    }
};


#endif //PAIR_PAIR_HPP
