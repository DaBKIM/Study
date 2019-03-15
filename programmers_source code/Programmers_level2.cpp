// Programmers - level 2

// H-index
// n편 중, h번 이상 인용된 논문이 h편 이상이고 
// 나머지 논문이 h번 이하 인용되었다면 h가 이 과학자의 H-Index

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 논문이 해당 위치의 숫자 이상 인용된 논문 횟수 저장
    int arr[citations.size()+1];
   
   // 초기화 
    for(int i=1;i<=citations.size();i++) arr[i]=0;
    
    // i번 이상 인용됨
    for(int i = 1;i<=citations.size();i++)
    	for(int j = 1;j<=citations.size();j++)
        	if(citations[j-1]>=i) arr[i]++;
    
    for(int i = 1 ; i<=citations.size();i++){
    	// i번 이상 인용된 i개 이상의 논문
        if(arr[i]>=i) answer=i;
    }
    
    return answer;
}