//
// Created by musta on 10.04.2016.
//

#ifndef HMM_ID_H
#define HMM_ID_H


class creature_ID {
private:
    unsigned int idNum;
public:
    creature_ID() {
        idNum = 0;
    }

    unsigned int get_id() {
        idNum++;
        return idNum;
    }
};

#endif //HMM_ID_H
