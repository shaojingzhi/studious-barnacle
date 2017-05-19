#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Image{
private: string filename;
public:	 
         double currentScore;
         double expectedWin;


        Image(string _filename) : filename(_filename), currentScore(1400), expectedWin(0.5) {}
 /*       float getCurrentScore();
        void setCurrentScore(float x);
        float getExpectedWin();
        void setExpectedWin(float x);*/
        void Show();

};

class Picture {
private: vector<Image> images;
	    // Image lostImage;
		// Image winImage;

public :
//	Picture()  {}
	pair<int, int> PickTwo(void);
	void UpdataScore(int winid, int loseid);
	void AddImage(string filename);
	void ShowId(int id);
private:
	float computeNewScore(int result,float oldScore,float expectedWin);

};

pair<int, int> Picture:: PickTwo(void){
	srand((int)time(NULL)); 
	//suppose the scores are between 1000 to 1800
	int num = images.size();
	int x = rand()%num ;
	int xscore = images[x].currentScore;
	vector<Image> temp;
	int a[num];//record the recordance of temp and images
	int cnt=0;
	for (int i = 0; i<num;i++ )
	{
		if (images[i].currentScore <xscore + 100&&images[i].currentScore >xscore - 100&&i!=x)
		{
			temp[cnt] = images[i];
			cnt++;
			a[cnt] = i;
		}
		
	}
	srand((int)time(NULL)); 
	int y = rand()%cnt;
	int j = 0;
	for (j = 0;j < num;j++)
	{
		if (a[y] = j)
		break;
	}
	pair<int,int> data = make_pair(x,j);
	return data;
}

void Picture::UpdataScore(int winid, int loseid){
	Image winImage = images[winid];
	Image lostImage = images[loseid];
	
	
	    if(winImage.currentScore == lostImage.currentScore){
        winImage.expectedWin = 0.5;
        lostImage.expectedWin = 0.5;
        return;
    }
    else{
        float winSub = lostImage.currentScore - winImage.currentScore;
        float wintemp = winSub/400;
        float lostSub = winImage.currentScore - lostImage.currentScore;
        float losttemp = lostSub/400;
        winImage.expectedWin = 1/(1+(float)pow(10,wintemp));
        lostImage.expectedWin = 1/(1+(float)pow(10,losttemp));
    }
        
    float oldScore = winImage.currentScore;
    winImage.currentScore = computeNewScore(1,oldScore,winImage.expectedWin);

    oldScore = lostImage.currentScore;
    lostImage.currentScore = computeNewScore(0,oldScore,lostImage.expectedWin);
    return;    

}

/*void Picture::computeExpectedWin(){
    if(winImage.currentScore == lostImage.currentScore){
        winImage.expectedWin = 0.5;
        lostImage.expectedWin = 0.5;
        return;
    }
    else{
        float winSub = lostImage.currentScore - winImage.currentScore;
        float wintemp = winSub/400;
        float lostSub = winImage.currentScore - lostImage.currentScore;
        float losttemp = lostSub/400;
        winImage.expectedWin = 1/(1+(float)pow(10,wintemp));
        lostImage.expectedWin = 1/(1+(float)pow(10,losttemp));
        return;
    }
}


void Picture::toComputeNewScore(){
    float oldScore = winImage.currentScore;
    winImage.currentScore = computeNewScore(1,oldScore,winImage.expectedWin);

    oldScore = lostImage.currentScore;
    lostImage.currentScore = computeNewScore(0,oldScore,lostImage.expectedWin);
    return;
	}
*/    
    
float Picture:: computeNewScore(int result,float oldScore,float expectedWin){
    float temp = result - expectedWin;
    float currentScore = oldScore + 10 * temp;
    return currentScore;
}


int main(){
    
}


