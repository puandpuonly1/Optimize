#include <iostream>

using namespace std;

int main() {
    cout << "Tinh tien nap RP cung Phat nhe!" << endl;
    pair <int, int> RP[8];
    RP[0] = {7500, 60200};
    RP[1] = {4400, 33500};
    RP[2] = {1800, 13500};
    RP[3] = {870, 6500};
    RP[4] = {610, 4500};
    RP[5] = {385, 2800};
    RP[6] = {195, 1380};
    RP[7] = {85, 575};
    int remain;
    cout << "Nhap so RP hien co: ";
    cin >> remain;
    int requiredAmount;
    cout << "Nhap so RP can co: ";
    cin >> requiredAmount;
    int purchase = requiredAmount - remain;
    if(purchase <= 0)
        cout << "May don mat voi t a ha?"; 
    else {
        int RP_2[8] = {};
        for(int i = 0; i < 8; i++) {
            if(purchase == 0)
                break;
            if(i == 7) {
                while(purchase > 0) {
                    purchase -= RP[i].second;
                    RP_2[i]++;
                }
            }
            while(purchase >= RP[i].second) {
                purchase -= RP[i].second;
                RP_2[i]++;
            }
        }
        int total = 0;
        for(int i = 0; i < 8; i++) {
            total += RP[i].first*RP_2[i]; 
        }
        int finalValue[8] = {};
        for(int i = 0; i < 8; i++) {
            if(total == 0)
                break;
            while(total >= RP[i].first) {
                total -= RP[i].first;
                finalValue[i]++;
            }
        }
        cout << "Cac goi can nap nhu sau: " << endl;
        for(int i = 0; i < 8; i++) {
            if(finalValue[i] != 0) {
                if(RP[i].first >= 1000)
                        cout << finalValue[i] << " goi " << RP[i].first/1000 << ",000,000 VND" << endl;
                else
                    cout << finalValue[i] << " goi " << RP[i].first << ",000 VND" << endl;
            }
        }
        cout << "Luu y: cac goi nap ben tren duoc tinh qua hinh thuc nap ZaloPay/ATM/Credit Card.";
    }
    return 0;
}