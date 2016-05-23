// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

#include <bits/stdc++.h>
using namespace std;

void ValidTriplet(vector<double> A) {
    vector<double> range1;
    vector<double> range2;
    vector<double> range3; 

	for(int i=0; i<A.size(); i++) {
		if(A[i] >0 && A[i] < (0.667)) {
			range1.push_back(A[i]);
	    }else if(A[i] >= (0.667) && A[i] < 1) {
			range2.push_back(A[i]);
	    } else
			range3.push_back(A[i]);
	}
	
	double firstrange1min, secondrange1min, firstrange2min, secondrange2min, firstrange2max;
	double firstrange1max, secondrange1max, thirdrange1max, firstrange3min;
	
	if(range1.size()>= 2) {
	    firstrange1min = min(range1[0], range1[1]);
	    secondrange1min = max(range1[0], range1[1]);
	    
	    for(int i=2; i<range1.size(); i++) {
    	    if(range1[i] <= firstrange1min) {
    	        secondrange1min = firstrange1min;
    	        firstrange1min = range1[i];
    	    } else if(range1[i] < secondrange1min) {
    	        secondrange1min = range1[i];
    	    }
	    }
	    
	    firstrange1max = secondrange1max = thirdrange1max = range1[0];
	    
	    for(int i=1; i< range1.size(); i++) {
	        if(range1[i] > firstrange1max) {
	            thirdrange1max = secondrange1max;
	            secondrange1max = firstrange1max;
	            firstrange1max = range1[i];
	        } else if(range1[i] > secondrange1max) {
	            thirdrange1max = secondrange1max;
	            secondrange1max = range1[i];
	        } else if(range1[i] > thirdrange1max)
	            thirdrange1max = range1[i];
	    }
	    if(range1.size() < 3)
	        thirdrange1max = 0;
	} 
	
	if(range2.size() >= 2) {
	    firstrange2min = min(range2[0], range2[1]);
    	secondrange2min = max(range2[0], range2[1]);
    	firstrange2max = secondrange2min;
    	
    	for(int i=2; i<range2.size(); i++) {
    	    if(range2[i] <= firstrange2min) {
    	        secondrange2min = firstrange2min;
    	        firstrange2min = range2[i];
    	    } else if(range2[i] < secondrange2min) {
    	        secondrange2min = range2[i];
    	    }
    	    if(range2[i] > firstrange2max)
    	        firstrange2max = range2[i];
    	}    
	}
	
	if(range3.size() >= 1) {
        firstrange3min = range3[0];
	
	    for(int i =1; i<range3.size(); i++) {
	        if(range3[i] < firstrange3min)
	            firstrange3min = range3[i];
	    }
	}
	
	if(range1.size() >= 3 &&  (firstrange1max + secondrange1max+thirdrange1max) >= 1 && (thirdrange1max != -1)) 
	    cout << "Yes" << endl;
	else if(range1.size() >= 2 && range3.size() >= 1 && (firstrange1min+secondrange1min+firstrange3min) < 2)
	    cout << "Yes" << endl;
	else if(range2.size()>= 2 && range1.size() >= 1 && (firstrange1min+secondrange2min+firstrange2min) < 2)
        cout << "Yes" << endl;
    else if(range1.size() >= 1 && range2.size() >= 1 && sizeof(range3) >=1 && (firstrange1min+firstrange2min+firstrange3min) < 2)
        cout << "Yes" << endl;
	else if(range1.size() >= 2 && range2.size() >= 1 && (firstrange1max+secondrange2min+firstrange1max) < 2)
	    cout << "Yes" << endl;
	else if(range1.size() >= 2 && range3.size() >= 1 && (firstrange1min+secondrange1min+firstrange2max) > 1)
	    cout << "Yes" << endl;
	 else
	    cout << "No" << endl;
}

int main() {

	vector<double> A;
    A.push_back(0.1);
    A.push_back(1.1);
    A.push_back(0.4);

    ValidTriplet(A);
    
    vector<double> A1;
    A1.push_back(0.5);
    A1.push_back(0.5);
    A1.push_back(0.5);
    
    ValidTriplet(A1);
    
    vector<double> A2;
    A2.push_back(1.5);
    A2.push_back(1.5);
    A2.push_back(1);

    ValidTriplet(A2);
    
    vector<double> A3;
    A3.push_back(0.5);
    A3.push_back(0.5);
    A3.push_back(1);
    ValidTriplet(A3);
    
    vector<double> A4;
    A4.push_back(0.1);
    A4.push_back(0.1);
    A4.push_back(0.5);
    A4.push_back(0.4);
    ValidTriplet(A4);

    vector<double> A5;
    A5.push_back(0.004);
    A5.push_back(0.45);
    A5.push_back(0.546);
    ValidTriplet(A5);
    
	return 0;
}