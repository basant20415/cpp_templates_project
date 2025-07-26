#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#include<type_traits>
using namespace std;

const int MOD = 1e9 + 7; 
const long long N=5e5+5;
long long f[N];

namespace max{
//max

// template<typename T,typename U, typename ... TS>
// auto mx(const T &a,const U &b,const TS &... c){
// // add the input values to a vector --> arrange the vector then output the last value as it will be the greatest
//   static_assert(is_arithmetic_v<T>&&is_arithmetic_v<U>&&(is_arithmetic_v<TS>&&...),"data types must be arithemetic");
//   using common_type=  common_type_t<T,U,TS...>;
//   //std::common_type<T, U, ...> is a C++ type trait that gives you the single type that all given types can be safely converted to without losing information.
//   vector<common_type>v{static_cast<common_type>(a),static_cast<common_type>(b),static_cast<common_type>(c)...};

// sort(v.begin(),v.end());
// return v.back();//or return *( v.end()-1);
// }


// another implementation

// template<typename T,typename ...TS>
// auto mx(const T &a,const TS& ...b){

//     if constexpr(sizeof ...(TS)>0){
// auto max_element=mx(TS...);

// return a>(max_element)?a:max_element;

//     }else return a;


// }

//

// another implementation
auto mx(){
    return 0;
}

template<typename T>
auto mx(const T &a){
    return a;
}

template<typename T,typename U,typename ...TS>
auto mx(const T &a,const U &b,const TS &...c){
    using common_type=common_type_t<T,U,TS...>;

common_type max_value=0;
    if(a>b)max_value= a;
    else max_value= b;
   return mx(max_value,c...);

}
};

namespace min{
// add the input values to a vector --> arrange the vector then output the first value as it will be the smallest
//     template<typename T,typename ...TS>
//     auto mn(const T &a,const TS& ...b){
//         static_assert(is_arithmetic_v<T>&&(is_arithmetic_v<TS>&&...),"data types must be arithmetic");
// using common_type=common_type_t<T,TS...>;
// vector<common_type>v{static_cast<common_type>(a),static_cast<common_type>(b)...};

// sort(v.begin(),v.end());
// return  v.front();



//     }

// another implementation

auto mn(){
    return 0;
}

template<typename T>
auto mn(const T &a){
    return a;
}

template<typename T,typename U ,typename ...TS>

auto mn(const T&a, const U &b,const TS& ...c){
    using common_type=common_type_t<T,U,TS...>;
     common_type min_value=1e6;
if(a<b)min_value=a;
else min_value=b;
return mn(min_value,c...);

}

};

namespace sum{

 auto accumulate(){
 return 0;
 }

 template<typename T>
 auto accumulate(const T&a){
 return a;
    }
template<typename T,typename U,typename ...TS>
auto accumulate(const T & a,const U& b,const TS &...values){
static_assert(is_arithmetic_v<T>&&is_arithmetic_v<U>&&(is_arithmetic_v<TS>&&...),"datatypes must be arithmetic");
auto r=a+b;
return r+accumulate(values...);


}

};

// namespace subtraction{

//     auto sub(){
//         return 0;
//     }
//     template <typename T>
//     auto sub(const T &a){
//         return a;
//     }
// template<typename T,typename U,typename ... TS>
// auto sub(const T& a,const U & b,const TS &...c){

// auto s=a-b;

// return sub(s,c...);



// }
// };

namespace average{

template <typename T,typename U,typename ...TS>
auto avg(const T &a,const U& b,const TS &... c)
{

    using common_type=common_type_t<T,U,TS...>;
    //std::common_type<T, U, ...> is a C++ type trait that gives you the single type that all given types can be safely converted to without losing information.
    vector<common_type>v{static_cast<common_type>(a),static_cast<common_type>(b),static_cast<common_type>(c)...};

auto acc=accumulate(v.begin(),v.end(),static_cast<common_type>(0));//using accumulate function to sum all the input values
auto total=v.size();
return acc/total;



}

};

// fast power is an algorithm that gets the power of a number in time complexity of O(log(power)) instead of using the naive way which uses time complexity of O(power)
// it depends on ---> the base ^2 and power/2 ,in case the power is odd multiply the return value by the base value
// for example:
// 2^10 ret=1
// 4*5  ret=1*4
// 16*2
// 256*1 ret=1*4*256=1024--->2^10
namespace fast_power{
template<typename T,typename U>
auto power(T base,U powr){
T ret=1;
while(powr){
if(powr%2==1) ret=(ret*base)%MOD;
base=(base*base)%MOD;
powr/=2;
}

return ret;

}

};


namespace prime_number{
template<typename T>
// bool prime(T num){
// // for checking if a number is prime or not we can iterate till the square root of this num if we found any number divisable by the input number we want to check then our number is not prime
//     for(int i=2;i*i<=num;i++){//we iterate till the square root of the input number 
//         //why?for example :
//         // if the input number to check is 16
//         // 1*16=16
//         // 2*8=16
//         // 4*4=16 so we can iterate till 4 if we continue we will be repeating the previous opertaions
//         // 8*2=16
//         // 16*1=16
//         if(num==1)return false;
//         if(num%i==0)return false;
//     }
// return true;
// }


// seive way for finding prime numbers
void seive(T num){

bool p[1000];
fill(p,p+1000,1);
p[0]=0,p[1]=0;
vector<T>primes;
for(T i=2;i<1000;i++){
if(p[i]){
primes.push_back(i);
for(T j=i*i;j<1000;j+=i)p[j]=0;
}

}

auto it = find(primes.begin(), primes.end(), num);

    if (it != primes.end()) {
      cout << "prime"; 
    } else {
       cout << "Not prime\n";
    }


}

};


namespace factorial{

template <typename T>
T fact (T num){
f[0]=1;
for (T i=1;i<N;i++){
    f[i]=(f[i-1]*i)%MOD;
    //if we want to get factorial of 30 ,it multiplies from 1-->30 so it will result overflow so we use the MOD
}
return f[num];

// another way using recursion
// if(num<=1)return 1;
//  return (num*fact(num-1))%MOD;
}
};


template <typename T>
class subtraction {

public :

auto sub(const T& a,const T & b){
auto s=a-b;
return s;
}
private:


};

template<>
class subtraction <string>{

public :

int  sub(const string & a,const string & b){
  int sub=  a.length()-b.length();
  return sub;
}

private:

};
