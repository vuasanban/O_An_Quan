//
// Created by DELL on 10/25/2020.
//

#include "Logic.h"

Logic::Logic() {}

Logic::~Logic() {}

Logic::Logic(vector<int> tiles_amt, vector <int> player_point) {
    this->tiles_amt = tiles_amt;
    this->player_point = player_point;
}

vector <int> Logic::getTilesAmount(int mark, int index, string key) {
    setupTilesAmt(mark, index, key);
    return tiles_amt;
}

bool Logic::check() {

}

void Logic::firstTimeSet() {
    tiles_amt.resize(13);
    for (int i = 1; i <= 12; i++){
        tiles_amt[i] = 5;
    }
    tiles_amt[6] = tiles_amt[12] = 10;
    player_point.resize(3);
    player_point[2] = player_point[1] = 0;
}

//void Logic::getPlayerPoint(vector<int> &a) {
//    a[1] = player_point[1];
//    a[2] = player_point[2];
//}

void Logic::setupTilesAmt(int mark, int index, string key) {
    if (key != "") {
        pickAndDropAndTake(mark, key, index);
        checkEmpty(index);
    }
}

int Logic::resetTilesAmt(int mark, int index) {
    int tmp;
    if (index == 1){
        tmp = tiles_amt[mark+1];
        tiles_amt[mark+1] = 0;
    }
    else{
        tmp = tiles_amt[12-(mark+1)];
        tiles_amt[12-(mark+1)] = 0;
    }

    return tmp;
}

void Logic::pickAndDropAndTake(int mark, string key, int index) {
    int tiles_process;
    if (index == 1) tiles_process = mark + 1;
    else tiles_process = 12 - (mark + 1);
    int share_amt = resetTilesAmt(mark, index);

    // ----------------Key: Right || Index: 1 -------------------
    if (key == "right" && index == 1) {
        while (share_amt--) {
            tiles_process++;
            if (tiles_process == 13) tiles_process = 1;
            tiles_amt[tiles_process]++;
            if (share_amt == 0) {
                if (tiles_process == 12) {
                    if (tiles_amt[1] != 0) {
                        share_amt = tiles_amt[1];
                        tiles_amt[1] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process++;
                        if (tiles_process == 13) tiles_process = 1;
                    }
                }
                else {
                    if (tiles_amt[tiles_process + 1] != 0) {
                        share_amt = tiles_amt[tiles_process + 1];
                        tiles_amt[tiles_process + 1] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process++;
                        if (tiles_process == 13) tiles_process = 1;
                    }
                }
            }
        }

        int add_point_pos;
        while (true){
            add_point_pos = tiles_process + 2;
            if (add_point_pos == 14) add_point_pos = 2;
            else if (add_point_pos == 13) add_point_pos = 1;

            if (tiles_amt[add_point_pos] == 0) break;
            player_point[1] += tiles_amt[add_point_pos];
            tiles_amt[add_point_pos] = 0;
        }



        cout << "Diem nguoi 1: " << player_point[1] << "\n" << "Diem nguoi 2: " << player_point[2] << "\n";

    }

    // ----------------Key: Right || Index: 2 -------------------
    if (key == "right" && index == 2){
        while (share_amt--){
            tiles_process--;
            if (tiles_process == 0) tiles_process = 12;
            tiles_amt[tiles_process]++;
            if (share_amt == 0){
                if (tiles_process == 1){
                    if (tiles_amt[12] != 0){
                        share_amt = tiles_amt[12];
                        tiles_amt[12] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process--;
                        if (tiles_process == 0) tiles_process = 12;
                    }
                }
                else{
                    if (tiles_amt[tiles_process-1] != 0) {
                        share_amt = tiles_amt[tiles_process - 1];
                        tiles_amt[tiles_process - 1] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process--;
                        if (tiles_process == 0) tiles_process = 12;
                    }
                }
            }
        }
        while (true){
            int add_point_pos = tiles_process - 2;
            if (add_point_pos == 0) add_point_pos = 12;
            else if (add_point_pos == -1) add_point_pos = 11;

            if (tiles_amt[add_point_pos] == 0) break;
            player_point[2] += tiles_amt[add_point_pos];
            tiles_amt[add_point_pos] = 0;
        }

        cout << "Diem nguoi 1: " << player_point[1] << "\n" << "Diem nguoi 2: " << player_point[2] << "\n";
    }

    // ----------------Key: Left || Index: 1 -------------------
    if (key == "left" && index == 1){
        while (share_amt--){
            tiles_process--;
            if (tiles_process == 0) tiles_process = 12;
            tiles_amt[tiles_process]++;
            if (share_amt == 0){
                if (tiles_process == 1){
                    if (tiles_amt[12] != 0){
                        share_amt = tiles_amt[12];
                        tiles_amt[12] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process--;
                        if (tiles_process == 0) tiles_process = 12;
                    }
                }
                else{
                    if (tiles_amt[tiles_process-1] != 0) {
                        share_amt = tiles_amt[tiles_process - 1];
                        tiles_amt[tiles_process - 1] = 0;
                        cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process--;
                        if (tiles_process == 0) tiles_process = 12;
                    }
                }
            }
        }
        while (true){
            int add_point_pos = tiles_process - 2;
            if (add_point_pos == 0) add_point_pos = 12;
            else if (add_point_pos == -1) add_point_pos = 11;

            if (tiles_amt[add_point_pos] == 0) break;
            player_point[1] += tiles_amt[add_point_pos];
            tiles_amt[add_point_pos] = 0;
        }

        cout << "Diem nguoi 1: " << player_point[1] << "\n" << "Diem nguoi 2: " << player_point[2] << "\n";
    }

    // ----------------Key: Left || Index: 2 -------------------
    if (key == "left" && index == 2){
        while (share_amt--){
            tiles_process++;
            //         cout << "\nO dang xet: " << tiles_process;
            if (tiles_process == 13) tiles_process = 1;
            tiles_amt[tiles_process]++;
            if (share_amt == 0){
                if (tiles_process == 12){
                    if (tiles_amt[1] != 0){
                        share_amt = tiles_amt[1];
                        tiles_amt[1] = 0;
                        //   cout << "\nSo hat chia tiep: " << share_amt;
                        tiles_process++;
                        if (tiles_process == 13) tiles_process = 1;
                    }
                }
                else{
                    if (tiles_amt[tiles_process+1] != 0) {
                        share_amt = tiles_amt[tiles_process + 1];
                        tiles_amt[tiles_process + 1] = 0;
//                            cout << "\nSo hat chia tiep: " << share_amt;
//                            cout << "\nHat: " << tiles_process+1;
                        tiles_process++;
                        if (tiles_process == 13) tiles_process = 1;
                    }
                }
            }
        }

        while (true){
            int add_point_pos = tiles_process + 2;
            if (add_point_pos == 14) add_point_pos = 2;
            else if (add_point_pos == 13) add_point_pos = 1;

            if (tiles_amt[add_point_pos] == 0) break;
            player_point[2] += tiles_amt[add_point_pos];
            tiles_amt[add_point_pos] = 0;
        }

        cout << "Diem nguoi 1: " << player_point[1] << "\n" << "Diem nguoi 2: " << player_point[2] << "\n";
    }
}

void Logic::checkEmpty(int index) {
    bool empty = true;
    if (index == 1){
        for (int i = 1; i <= 5; i++){
            if (tiles_amt[i] != 0) empty = false;
        }
        if (empty){
            player_point[1] -= 5;
            for (int i = 1; i <= 5; i++){
                tiles_amt[i] = 1;
            }
        }
    }
    else if (index == 2){
        for (int i = 7; i <= 11; i++){
            if (tiles_amt[i] != 0) empty = false;
        }
        if (empty){
            player_point[1] -= 5;
            for (int i = 7; i <= 11; i++){
                tiles_amt[i] = 1;
            }
        }
    }
}