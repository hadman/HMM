//
// Created by musta on 10.04.2016.
//

#ifndef HMM_ID_H
#define HMM_ID_H


static int idNum = 0;

class creature_ID {
public:

    static unsigned int get_id() {
        idNum++;
        return idNum;
    }
};

#endif //HMM_ID_H
