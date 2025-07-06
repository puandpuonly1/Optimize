#include <iostream>
#include <vector>

using namespace std;

class Valorant {
protected:
    int remain;
    int requiredAmount;
    pair <int, int> VP[8] = {};
public:
    void Finalize()
    {
        cout << "Nhap so VP hien co: ";
        cin >> remain;
        cout << "Nhap so VP can co: ";
        cin >> requiredAmount;
        int purchase = requiredAmount - remain;
        if(purchase <= 0)
            cout << "May don mat voi t a ha?"; 
        else {
            int VP_2[8] = {};
            for(int i = 0; i < 8; i++) {
                if(purchase == 0)
                    break;
                if(i == 7 || VP[i+1].second == 0) {
                    while(purchase > 0) {
                        purchase -= VP[i].second;
                        VP_2[i]++;
                    }
                    break;
                }
                while(purchase >= VP[i].second) {
                    purchase -= VP[i].second;
                    VP_2[i]++;
                }
            }
            int total = 0;
            for(int i = 0; i < 8; i++) {
                total += VP[i].first*VP_2[i]; 
            }
            int finalValue[8] = {};
            for(int i = 0; i < 8; i++) {
                if(total == 0)
                    break;
                while(total >= VP[i].first) {
                    total -= VP[i].first;
                    finalValue[i]++;
                }
            }
            cout << "Cac goi can nap nhu sau: " << endl;
            for(int i = 0; i < 8; i++) {
                if(finalValue[i] != 0) {
                    if(VP[i].first >= 1000)
                        cout << finalValue[i] << " goi " << VP[i].first/1000 << ",000,000 VND" << endl;
                    else
                        cout << finalValue[i] << " goi " << VP[i].first << ",000 VND" << endl;
                }
            }
        }
    }
    int Total_Money() {
        int VP_2[8] = {};
        int purchase = requiredAmount - remain;
        for(int i = 0; i < 8; i++) {
                if(purchase == 0)
                    break;
                if(i == 7 || VP[i+1].second == 0) {
                    while(purchase > 0) {
                        purchase -= VP[i].second;
                        VP_2[i]++;
                    }
                    break;
                }
                while(purchase >= VP[i].second) {
                    purchase -= VP[i].second;
                    VP_2[i]++;
                }
            }
            int total = 0;
            for(int i = 0; i < 8; i++) {
                total += VP[i].first*VP_2[i]; 
            }
        return total;
    }
    int Total_VP() {
        int VP_2[8] = {};
        int purchase = requiredAmount - remain;
        for(int i = 0; i < 8; i++) {
                if(purchase == 0)
                    break;
                if(i == 7 || VP[i+1].second == 0) {
                    while(purchase > 0) {
                        purchase -= VP[i].second;
                        VP_2[i]++;
                    }
                    break;
                }
                while(purchase >= VP[i].second) {
                    purchase -= VP[i].second;
                    VP_2[i]++;
                }
            }
            int total = 0;
            for(int i = 0; i < 8; i++) {
                total += VP[i].second*VP_2[i]; 
            }
        return total;
    }
    void Copy(Valorant x) {
        remain = x.remain;
        requiredAmount = x.requiredAmount;
    }
};
class ZaloPay : public Valorant {
public:
    ZaloPay() {
    VP[0] = {2000, 13250};
    VP[1] = {1000, 6550};
    VP[2] = {500, 3040};
    VP[3] = {200, 1220};
    VP[4] = {100, 610};
    VP[5] = {50, 275};
    VP[6] = {20, 110};
    VP[7] = {10, 52};
    }
};
class Zing_Card : public Valorant {
public:
    Zing_Card() {
    VP[0] = {500, 2895};
    VP[1] = {200, 1100};
    VP[2] = {100, 535};
    VP[3] = {50, 268};
    VP[4] = {20, 105};
    VP[5] = {10, 50};
    }
};
class ATM : public Valorant {
public:
    ATM() {
        VP[0] = {2000, 12660};
        VP[1] = {1000, 6160};
        VP[2] = {500, 2860};
        VP[3] = {200, 1090}; 
        VP[4] = {100, 530};
        VP[5] = {50, 255};
    }
};
class Credit_Card : public ATM {
public:
    Credit_Card() {
        ATM:ATM();
        VP[5] = {50, 255};
    }
};
class VP {
private:
    Valorant *VP;
public:
    void Nap() {
        int type = -1;
        while(type != 0 && type != 1 && type != 2 && type != 3) {
            cout << "Nhap loai can nap (0: ZaloPay, 1: Zing Card, 2: ATM hoac 3: Credit Card): ";
            cin >> type;
        }
        if(type == 0)
            VP = new ZaloPay;
        else if(type == 1)
            VP = new Zing_Card;
        else if(type == 2)
            VP = new ATM;
        else
            VP = new Credit_Card;
        VP->Finalize();
    }
    void Optimize() {
        Valorant *vp[4];
        vp[0] = new ZaloPay;
        vp[1] = new Zing_Card;
        vp[2] = new ATM;
        vp[3] = new Credit_Card;
        for(int i = 0; i < 4; i++)
            vp[i]->Copy(*VP);
        int Min_Money = 10e9;
        for(int i = 0; i < 4; i++)
            if(vp[i]->Total_Money() < Min_Money)
                Min_Money = vp[i]->Total_Money();
        vector <int> check;
        for(int i = 0; i < 4; i++)
            if(vp[i]->Total_Money() == Min_Money)
                check.push_back(i);
        if(check.size() == 1)  {
            cout << "Nap toi uu nhat thong qua: " << (check[0] == 0 ? "ZaloPay" : (check[0] == 1 ? "Zing Card" : (check[0] == 2 ? "ATM" : "Credit Card")));
        }
        else {
            cout << "Nap toi uu nhat thong qua: " << endl;
            int Min_VP = 10e9;
            for(int i = 0; i < check.size(); i++)
                if(vp[check[i]]->Total_VP() < Min_VP)
                    Min_VP = vp[check[i]]->Total_VP();
            for(int i = 0; i < check.size(); i++)
                if(vp[check[i]]->Total_VP() == Min_VP)
                    cout << (check[i] == 0 ? "ZaloPay" : (check[i] == 1 ? "Zing Card" : (check[i] == 2 ? "ATM" : "Credit Card"))) << endl;
        }
    }
};
int main() {
    cout << "Tinh tien nap VP cung Phat nhe!" << endl;
    VP x;
    x.Nap();
    int optimize = -1;
    while(optimize != 0 && optimize != 1) {
        cout << "Muon toi uu nap khong? (0: Khong or 1: Co): ";
        cin >> optimize;
    }
    if(optimize == 1) {
        x.Optimize();
    }
    cout << endl;
    cout << "Viec nap toi uu dua tren so tien can nap vao it nhat. Neu so tien can nap vao la bang nhau, xet den so VP co duoc sau khi nap la cao nhat." << endl;
    return 0;
}