// Programmers - level 1

// 소수의 합
// 에라토스테네스의 체 사용

#include <vector>
#include<stdlib.h>

using namespace std;

// 0~N 사이의 소수의 합 구하기
long long solution(int N) { 
    
    long long answer = 0;
    
    // 배열 생성 long long이 안전할 것으로 보임
    // 모든 배열에 해당 번지 수와 값은 값 삽입
    int *arr = (int*)malloc(sizeof(int)*N);
    for(int i = 0 ; i<=N;i++){
        arr[i]=i;
    }
    
    // 소수 2부터 N까지 서치
    for(int i = 2 ; i<=N; i++){
        
        // arr[i]가 0일 경우(소수 아님, 이미 체크) skip
        if(arr[i]==0) continue;
        else{
        	// 그 외의 경우 i의 배수를 전부 0으로 체크
            for(int j= i+i ; j<=N ; j+=i){
                arr[j] = 0;
            }
        }
        
        // 배열의 값이 0이 아닐 경우 소수
        if(arr[i]!=0) answer+=i;
    }
    
    return answer;
}



// 완주하지 못한 선수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 참가선수 리스트와 완주 리스트를 통해 완주하지 못한 선수 찾기
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 두 리스트를 각각 sort진행
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    // 두 리스트의 차이점은 완주하지 못한 선수 한명이므로,
    // sort되어 있는 리스트의 같은 위치에 다른 이름이 있으면 해당 참가자 출력
    for(int i = 0 ;i<participant.size();i++){ // participant -> comletion 
        if(participant[i]!=completion[i]){
            answer = participant[i];
            break;
        }
        else continue;
    }
    // 해당 포문의 조건으로 participant의 계수가 더 많으므로,
    // participant 보다 completion의 계수를 조건으로 두어
    // 포문완료 후에 다른점을 찾지 못했다면 마지막 participant를 출력하는 방법으로 개선 필요
    // participant가 size가 1 더 큼으로 segmentation fault 발생 가능 성 있음
    /*
    if(answer == ""){
    	answer = participant[participant.size()-1];
    }*/
    
    return answer;
}



// 모의고사
// 패턴찾기

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;
    
    int t1=0,t2=0,t3=0; // 수포자 1,2,3
    
    for(int i = 1 ;i<=answers.size();i++){
        
        int j = i-1;
        
        //t1 - 1 2 3 4 5 1 2 3 4 5....
        if(answers[j]%5==i%5) t1++;
        
        //t3 - 3 3 1 1 2 2 4 4 5 5....
        if(i%10==1 || i%10==2)
            if(answers[j]==3) t3++;
        if(i%10==3 || i%10==4)
            if(answers[j]==1) t3++;
        if(i%10==5 || i%10==6)
            if(answers[j]==2) t3++;
        if(i%10==7 || i%10==8)
            if(answers[j]==4) t3++;
        if(i%10==9 || i%10==0)
            if(answers[j]==5) t3++;
        
        //t2 - 2 1 2 3 2 4 2 5....
        // i가 홀수 -> 무조건 2
        // i가 짝수 -> 8i+2/4/6/8 순서대로 1 3 4 5
        if(i%2!=0){
            if(answers[j]==2) t2++;
        }
        else{
            if(i%8 == 0){
                if(answers[j]==5){
                    t2++;
                    continue;
                }
            }
            else if((i-6)%8 == 0){
                if(answers[j]==4){
                    t2++;
                    continue;
                }
            }
            else if((i-4)%8 == 0){
                if(answers[j]==3){
                    t2++;
                    continue;
                }
            }
            else if((i-2)%8 == 0){
                if(answers[j]==1){
                    t2++;
                    continue;
                }
            }
        }
    }
    
    // 다른 두 수보다 크거나 같으면 무조건 answer에 포함
    if((t1>=t2) && (t1>=t3)) answer.push_back(1);
    if((t2>=t1) && (t2>=t3)) answer.push_back(2);
    if((t3>=t1) && (t3>=t2)) answer.push_back(3);
    
    return answer;
}


// K번째수
// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        
        // f 부터 e 까지의 수
        int f = commands[i][0]; // i번째 수 
        int e = commands[i][1]; // j번째 수
        int num = commands[i][2]; // k 번째 수
        vector<int> cut;
        
        // f부터 e까지의 수를 다른 vector에 따로 저장 후 정렬
        for(int j=f;j<=e;j++) cut.push_back(array[j-1]);
        sort(cut.begin(),cut.end());
        
        // k번째 있는 수
        answer.push_back(cut[num-1]);
        
    }
    return answer;
}


// 체육복
// 그리디 알고리즘
// 전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 
// 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 
// 체육수업을 들을 수 있는 학생의 최댓값을 return

// 본인 번호의 앞사람이나 뒷사람의 체육복만 빌릴 수 있다

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = 0;
    // check : 각자 가지고 있는 체육복의 수
    int check[n+1];
    
    // 체육복의 수 전체 파악
    for(int i=1;i<n+1;i++){
        check[i] = 1;
        for(int j = 0; j<lost.size();j++){
            if(lost[j] == i) check[i]--;
        }
        for(int j = 0 ; j<reserve.size();j++){
            if(reserve[j]==i) check[i]++;
        }
    }
    
    // 체육복의 수가 2인 앞사람 또는 뒷사람에게 체육복 빌리기
    for(int i = 1;i<n+1;i++){
        
        if(i==1 && check[i] == 0){
            if(check[i+1] > 1){
                check[i]++;
                check[i+1]--;
            }
        }
        if(i>1 && i<n &&check[i] == 0){
            if(check[i-1] == 2){
                check[i-1]--;
                check[i]++;
            }else if(check[i+1] == 2){
                check[i+1]--;
                check[i]++;
            }
        }
        if(i == n && check[i] == 0){
            if(check[i-1] == 2){
                check[i]++;
                check[i-1]--;
            }
        }
    }
    
    // 0이 아닌 값을 가짐 == 체육복을 빌림/소유
    for(int i = 1; i<n+1;i++){
        if(check[i] > 0) answer++;
    }
    
    return answer;
}