/**
  * @file    Couple.hpp
  * @version 1.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   Es la API de una pareja de datos de diferente tipo
  */

#ifndef COUPLE_COUPLE_HPP
#define COUPLE_COUPLE_HPP

template <typename ItemOne, typename ItemTwo>
class Couple {
private:
    ItemOne first;
    ItemTwo last;
public:
    //Constructor
    Couple(){

    }
    
    Couple(ItemOne _first, ItemTwo _last){
        first = _first;
        last = _last;
    }

    //Destructor
    ~Couple(){
      
    }

    //Getters
    ItemOne getOne() const {return first;}
    ItemTwo getTwo() const {return last;}

    //Setters
    void setOne(ItemOne _first){first = _first;};
    void setTwo(ItemTwo _last){last = _last;}

};


#endif //COUPLE_COUPLE_HPP
