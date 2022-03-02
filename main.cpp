#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
bool isPrime(int n);
void menu();
class Integer{
    private:
        int n;
    public:
        Integer(int n = -1){this->n=n;}
        void setN(int n){this->n = n;}
        void input();
        void printDivisorsOfN();
        void printPrimeNumbersLessN();
        int getN(){return n;}
        int countNumberChar();
        int sumOfNumberChar();
        int reverseNumber();
        int maxNumberChar();
        int minNumberChar();
        int sumFrom1toN();
        int sumSquare1toN();
        int sumEvenNumberLessThanN();
        int sumOddNumberLessThanN();
        int primeNumberGreatN();
        int primeNumberLessN();
        bool isEvenNumber(){return n % 2 == 0;}
        bool isOddNumber(){return n % 2 != 0;}
        bool isIncreaseNumber();
        bool isDecreaseNumber();
        bool isPalindromeNumber();
};
void Integer::printPrimeNumbersLessN(){
     cout<<"Các số nguyên tố nhỏ hơn bằng  "<<n<<": ";
     for(int i = 2;i <= n;i++){
         if(isPrime(i)){
             cout<<i<<" ";
         }
     }
    cout<<"\n";
}
void Integer::printDivisorsOfN(){
    cout<<"Các uớc của "<<n<<": ";
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}
void Integer::input(){
    while(n <= 0){
        cout<<"Nhập 1 số nguyên > 0: ";
        cin>>n;
    }
}
int Integer::sumEvenNumberLessThanN(){
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            s += i;
        }
    }
    return s;
}
int Integer::sumOddNumberLessThanN(){
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 != 0){
            s += i;
        }
    }
    return s;
}
int Integer::sumFrom1toN(){
    int s = 0;
    for (int i = 1; i <= n; i++){
        s += i;
    }
    return s;
}
int Integer::sumSquare1toN(){
    int s = 0;
    for (int i = 1; i <= n; i++){
        s += i*i;
    }
    return s;
}
int Integer::countNumberChar(){
    string temp = to_string(n);
    return temp.size();
}
int Integer::sumOfNumberChar(){
    int s = 0, temp = n;
    while(temp > 0){
        s += temp%10;
        temp/=10;
    }
    return s;
}
int Integer::reverseNumber(){
    int s = 0, temp = n;
    while(temp > 0){
        s = s*10 + temp%10;
        temp/=10;
    }
    return s;
}
int Integer::maxNumberChar(){
    vector<int>vt;
    int temp = n;
    while(temp > 0){
        vt.push_back(temp%10);
        temp/=10;
    }
    sort(vt.begin(),vt.end());
    return vt[vt.size()-1];
}
int Integer::minNumberChar(){
    vector<int>vt;
    int temp = n;
    while(temp > 0){
        vt.push_back(temp%10);
        temp/=10;
    }
    sort(vt.begin(),vt.end());
    return vt[0];
}
int Integer::primeNumberGreatN(){
    int temp = n + 1;
    while(!isPrime(temp)){
        temp++;
    }
    return temp;
}
int Integer::primeNumberLessN(){
    if(n <= 2) return 0;
    int temp = n - 1;
    while(!isPrime(temp)){
        temp--;
    }
    return temp;
}
bool Integer::isIncreaseNumber(){
    vector<int>vt;
    int temp = n;
    while(temp > 0){
        vt.push_back(temp%10);
        temp/=10;
    }
    bool flag = true;
    for(int i = 0; i < vt.size(); i++){
        if(vt[i] <= vt[i+1]){
            flag = false;
            break;
        }
    }
    return flag;
}
bool Integer::isDecreaseNumber(){
    return !this->isIncreaseNumber();
}
bool Integer::isPalindromeNumber(){
    vector<int>vt;
    int temp = n;
    while(temp > 0){
        vt.push_back(temp%10);
        temp/=10;
    }
    int len = vt.size();
    for(int i = 0; i < len/2; i++){
        if (vt[i] != vt[len-i-1])
            return false;
    }
    return true;
}
int main() {
    menu();
    return 0;
}
bool isPrime(int n){
    if(n<=1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
  
    return true;
}
void menu(){
    Integer n;
    int i = 0;
    while(1){
        cout<<"Menu: "<<endl;
        cout<<"1. Nhập N"<<endl;
        cout<<"2. Kiểm tra N là chẳn hay lẻ"<<endl;
        cout<<"3. Kiểm tra N có phải số nguyên tố"<<endl;
        cout<<"4. Kiểm tra N có bao nhiêu chữ số"<<endl;
        cout<<"5. Tính tổng các chữ số của N"<<endl;
        cout<<"6. Kiểm tra N có phải số tăng hay giảm hay ko tăng ko giảm"<<endl;
        cout<<"7. Tìm số đảo ngược của N"<<endl;
        cout<<"8. Kiểm tra N có phải số đối xứng"<<endl;
        cout<<"9. Tìm chữ số lớn nhất // nhỏ nhất của N"<<endl;
        cout<<"10. Liệt kê tất cả ước số của N"<<endl;
        cout<<"11. Liệt kế tất cả các số nguyên tố trong dãy từ 1 --> N"<<endl;
        cout<<"12. Tính S=1+2+3+...+N"<<endl;
        cout<<"13. Tính S=1^2+2^2+3^2+...+N^2"<<endl;
        cout<<"14. Tính SC=2+4+6+...+N"<<endl;
        cout<<"15. Tính SL=1+3+5+...+N"<<endl;
        cout<<"16.Tìm số nguyên tố T gần N nhất và T > N"<<endl;
        cout<<"17. Tìm số nguyên tố T gần N nhất và T < N"<<endl;
        cout<<"0. Thoát"<<endl;
        int choose;
        while (1){
            cout<<"Nhập lựa chọn của bạn: ";
            cin>>choose;
            if (choose>=0 && choose<=17)
                break;
        }
        switch(choose){
            case 0:
                cout<<"Đang thoát..."<<endl;
                return;
            case 1:
                n.input();
                sleep(1);
                break;
            case 2:
                if(n.getN() != -1){
                    if(n.isEvenNumber())
                    cout<<n.getN()<<" là số chẳn!"<<endl;
                    else if(n.isOddNumber())
                    cout<<n.getN()<<" là số lẻ!"<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 3:
                if(n.getN() != -1){
                    if(isPrime(n.getN())){
                        cout<<n.getN()<<" là số nguyên tố!"<<endl;
                    }
                    else{
                        cout<<n.getN()<<" không là số nguyên tố!"<<endl;
                    }
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 4: 
                if(n.getN() != -1){
                   cout<<n.getN()<<" có "<<n.countNumberChar()<<" chữ số!"<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 5:
                if(n.getN() != -1){
                   cout<<"Tổng các chữ số của "<<n.getN()<<" : "<<n.sumOfNumberChar()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 6:
                if(n.getN() != -1){
                   if(n.isIncreaseNumber())
                    cout<<n.getN()<<" là số tăng!"<<endl;
                  else if(n.isDecreaseNumber())
                    cout<<n.getN()<<" là số giảm!"<<endl;
                else
                    cout<<n.getN()<<" là số không tăng, không giảm!"<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 7:
                if(n.getN() != -1){
                   cout<<"Số đảo ngược của "<<n.getN()<<" là: "<<n.reverseNumber()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 8:
                if(n.getN() != -1){
                   if(n.isPalindromeNumber())
                        cout<<n.getN()<<" là số đối xứng!"<<endl;
                    else
                        cout<<n.getN()<<" không là số đối xứng!"<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 9:
                if(n.getN() != -1){
                   cout<<"Chữ số lớn nhất của "<<n.getN()<<" là: "<<n.maxNumberChar()<<endl;
                   cout<<"Chữ số nhỏ nhất của "<<n.getN()<<" là: "<<n.minNumberChar()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 10:
                if(n.getN() != -1){
                   n.printDivisorsOfN();
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 11:
                if(n.getN() != -1){
                   n.printPrimeNumbersLessN();
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 12:
                if(n.getN() != -1){
                   cout<<"Tổng các số bé hơn bằng "<<n.getN()<<" là: "<<n.sumFrom1toN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 13:
                if(n.getN() != -1){
                   cout<<"Tổng bình phương của các số bé hơn bằng "<<n.getN()<<" là: "<<n.sumSquare1toN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 14:
                if(n.getN() != -1){
                   cout<<"Tổng các số chẳn bé hơn bằng "<<n.getN()<<" là:"<<n.sumEvenNumberLessThanN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 15:
                if(n.getN() != -1){
                   cout<<"Tổng các số lẻ bé hơn bằng "<<n.getN()<<" là:"<<n.sumOddNumberLessThanN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 16:
                if(n.getN() != -1){
                   cout<<"Số nguyên tố lớn hơn "<<n.getN()<<" gần "<<n.getN()<<" là: "<<n.primeNumberGreatN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
            case 17:
                if(n.getN() != -1){
                   cout<<"Số nguyên tố bé hơn "<<n.getN()<<" gần "<<n.getN()<<" là: "<<n.primeNumberLessN()<<endl;
                }
                else
                    cout<<"Chưa nhập dữ liệu!"<<endl;
                sleep(1);
                break;
        }
        cout<<"-------------------------------------------"<<endl;

    }
}
