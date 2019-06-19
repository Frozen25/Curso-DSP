#include "filteradapter.h"
#include <iostream>
using namespace std;



float FilterAdapter::filter_697 [15] = {
	0.01686987953088016, 0, -0.01686987953088016, 1.9675302859870418, -0.9766652729571003,// b0, b1, b2, a1, a2
	0.25, -0.5, 0.25, 1.9825389952065444, -0.989707757221651,// b0, b1, b2, a1, a2
	0.00048828125, 0.0009765625, 0.00048828125, 1.975050201191215, -0.9868260425382949// b0, b1, b2, a1, a2
};
float FilterAdapter::filter_770 [15]= {
	0.007475625331410288, 0, -0.007475625331410288, 1.9771136027331977, -0.9887717119280632,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9841464351230285, -0.9946658825554913,// b0, b1, b2, a1, a2
	0.00048828125, 0.0009765625, 0.00048828125, 1.9810822383489624, -0.9940746788977574// b0, b1, b2, a1, a2
};
float FilterAdapter::filter_852[15] = {
	0.008206206740402575, 0, -0.008206206740402575, 1.976116217297779, -0.990803843875821,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9819374307320652, -0.9955678980878409,// b0, b1, b2, a1, a2
	0.000244140625, 0.00048828125, 0.000244140625, 1.9793155344779982, -0.9952149883329666// b0, b1, b2, a1, a2
};
float FilterAdapter::filter_941 [15]= {
	0.004878341911645924, 0, -0.004878341911645924, 1.9759706406348159, -0.9938598273011479,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9798945840123845, -0.9969963914908996,// b0, b1, b2, a1, a2
	0.0001220703125, 0.000244140625, 0.0001220703125, 1.9780838441040673, -0.9968540610043004// b0, b1, b2, a1, a2
};




float FilterAdapter::filter_1209 [15]= {
	0.011242166570338979, 0, -0.011242166570338979, 1.9601676599812337, -0.9897872600604538,// b0, b1, b2, a1, a2
	0.03125, -0.0625, 0.03125, 1.9670703282673947, -0.995033155911778,// b0, b1, b2, a1, a2
	0.00048828125, 0.0009765625, 0.00048828125, 1.9631937547687417, -0.9947282631173735// b0, b1, b2, a1, a2
};

float FilterAdapter::filter_1336 [15]= {
	0.015364948835154659, 0, -0.015364948835154659, 1.9505773701999538, -0.9857312638283043,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9604510462045033, -0.9931132817572369,// b0, b1, b2, a1, a2
	0.00048828125, 0.0009765625, 0.00048828125, 1.9544627352049015, -0.9925677351225776// b0, b1, b2, a1, a2
};

float FilterAdapter::filter_1477 [15]= {
	0.022252680515597215, 0, -0.022252680515597215, 1.9360494903625507, -0.9796780917565633,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9505474852601827, -0.9902839387861799,// b0, b1, b2, a1, a2
	0.0009765625, 0.001953125, 0.0009765625, 1.9409055939336748, -0.9892928364334187// b0, b1, b2, a1, a2
};

float FilterAdapter::filter_1633 [15]= {
	0.0024380376888168743, 0, -0.0024380376888168743, 1.9401403597063511, -0.9938598273011477,// b0, b1, b2, a1, a2
	0.03125, -0.0625, 0.03125, 1.944583439703875, -0.9969657360579519,// b0, b1, b2, a1, a2
	0.00048828125, 0.0009765625, 0.00048828125, 1.9416249549556757, -0.9968847130033816// b0, b1, b2, a1, a2
};


FilterAdapter::FilterAdapter()
{
	in = 0;
	f = DtmfTone_create();
	min_energy = 0.0005f;
	callState = IDLE;
}

char FilterAdapter::getKey(){
	DtmfTone_filterBlock(f,in,out697,size,filter_697);
	DtmfTone_filterBlock(f,in,out770,size,filter_770);
	DtmfTone_filterBlock(f,in,out852,size,filter_852);
	DtmfTone_filterBlock(f,in,out941,size,filter_941);
	DtmfTone_filterBlock(f,in,out1209,size,filter_1209);
	DtmfTone_filterBlock(f,in,out1336,size,filter_1336);
	DtmfTone_filterBlock(f,in,out1477,size,filter_1477);
	DtmfTone_filterBlock(f,in,out1633,size,filter_1633);

	float e697 = 0;
	float e770 = 0;
	float e852 = 0;
	float e941 = 0;
	float e1209 = 0;
	float e1336 = 0;
	float e1477 = 0;
	float e1633 = 0;


	for (int i = 0; i < size;i++){
		e697 += out697[i] * out697[i];
		e770 += out770[i] * out770[i];
		e852 += out852[i] * out852[i];
		e941 += out941[i] * out941[i];
		e1209 += out1209[i] * out1209[i];
		e1336 += out1336[i] * out1336[i];
		e1477 += out1477[i] * out1477[i];
		e1633 += out1633[i] * out1633[i];
	}


	e697 /=size;
	e770 /=size;
	e852 /=size;
	e941 /=size;
	e1209 /=size;
	e1336 /=size;
	e1477 /=size;
	e1633 /=size;

	int row = 0;
	if (e697 > e770 && e697 > e852 && e697 > e941 && e697 > min_energy){
		//cout << "H: 697 " << e697 << " ";
		row = 1;
	}
	else if (e770 > e697 && e770 > e852 && e770 > e941 && e770> min_energy){
		//cout << "H: 770 "<< e770 << " ";
		row = 2;
	}
	else if (e852 > e697 && e852 > e770 && e852 > e941 && e852> min_energy){
		//cout << "H: 852 " << e852 << " ";
		row = 3;
	}
	else if (e941 > e697 && e941 > e852 && e941 > e770 && e941> min_energy){
		//cout << "H: 941 " << e941 << " " << e770 << " " << e852 << " " << e941;//<< endl;
		row = 4;
	}
	//cout << " ";

	//if(row == 4)cout << "V: 1336 " << e1336;
	int col = 0;
	if (e1209 > e1336 && e1209 > e1477 && e1209 > e1633 && e1209 > min_energy){
		//if(row == 4)cout << "V: 1209 " << e1209 << endl;
		col = 1;
	}
	else if (e1336 > e1209 && e1336 > e1477 && e1336 > e1633 && e1336 > min_energy){
		//if(row == 4)cout << "V: 1336 " << e1336 << endl;
		col = 2;
	}
	else if (e1477 > e1209 && e1477 > e1336 && e1477 > e1633 && e1477 > min_energy){
		//if(row == 4)cout << "V: 1477 " << e1477 << endl;
		col = 3;
	}
	else if (e1633 > e1209 && e1633 > e1336 && e1633 > e1477 && e1633 > min_energy){
		//if(row == 4)cout << "V: 1633 " << e1633 << endl;
		col = 4;
	}

	if(digits.size() == 10) digits.erase (digits.begin());
	//cout << endl;
	if (row == 1 && col == 1){
		digits.push_back('1');
		cout << "Tecla 1"<< endl;
	}
	else if (row == 1 && col == 2){
		cout << "Tecla 2" << endl;

		digits.push_back('2');
	}
	else if (row == 1 && col == 3){
		cout << "Tecla 3" << endl;

		digits.push_back('3');
	}
	else if (row == 1 && col == 4){
		cout << "Tecla A" << endl;

		digits.push_back('a');
	}
	else if (row == 2 && col == 1){
		cout << "Tecla 4" << endl;

		digits.push_back('4');
	}
	else if (row == 2 && col == 2){
		cout << "Tecla 5" << endl;

		digits.push_back('5');
	}
	else if (row == 2 && col == 3){
		cout << "Tecla 6" << endl;

		digits.push_back('6');
	}
	else if (row == 2 && col == 4){
		cout << "Tecla B" << endl;

		digits.push_back('b');
	}
	else if (row == 3 && col == 1){
		cout << "Tecla 7" << endl;

		digits.push_back('7');
	}
	else if (row == 3 && col == 2){
		cout << "Tecla 8" << endl;

		digits.push_back('8');
	}
	else if (row == 3 && col == 3){
		cout << "Tecla 9" << endl;

		digits.push_back('9');
	}
	else if (row == 3 && col == 4){
		cout << "Tecla C" << endl;

		digits.push_back('c');
	}
	else if (row == 4 && col == 1){
		cout << "Tecla *" << endl;

		digits.push_back('*');
	}
	else if (row == 4 && col == 2){
		cout << "Tecla 0" << endl;

		digits.push_back('0');
	}
	else if (row == 4 && col == 3){
		cout << "Tecla #" << endl;

		digits.push_back('#');
	}
	else if (row == 4 && col == 4){
		cout << "Tecla D" << endl;

		digits.push_back('d');
	}

	delete[] out697;
	delete[] out770;
	delete[] out852;
	delete[] out941;
	delete[] out1209;
	delete[] out1336;
	delete[] out1477;
	delete[] out1633;

	if(digits.size() == 10) for (unsigned int i = 0; i < digits.size(); i++)cout << digits[i];
	char myNum[10] = {'*','8','9','8','8','0','6','5','4','#'};
	char emergency[5] = {'*','9','1','1','#'};
	char tram[2] = {'*','#'};
	bool isMyNum = true;
	for (unsigned int i = 0; i < digits.size(); i++){
		if(myNum[i] != digits.at(i)){
			isMyNum = false;
			break;
		}
	}
	bool isEmergency = true;
	if (digits.size() > 4 )
		for (unsigned int x = 0; x < 5; x++){
			if (digits[digits.size()-1 - x] != emergency[4-x]){
				isEmergency = false;
			}
		}
	else isEmergency = false;

	if (isMyNum  && digits.size() == 10 || isEmergency){ //&& callState != RINGING){
		cout << "Estas recibiendo una llamada " << endl;
		callState = RINGING;
		t = high_resolution_clock::now();
		digits.erase (digits.begin());
	}
	char tram[2] = {'*','#'};
	bool isTram = true;
	if (digits.size() > 1 )
		for (unsigned int x = 0; x < 5; x++){
			if (digits[digits.size()-1 - x] != tram[1-x]){
				isTram = false;
			}
		}
	else isTram = false;

	if (isTram && callState == TYPING_KEYS){
		onCall();
	}


	return 'c';

}

void FilterAdapter::setInput(float *input, int size){
	//delete in;
	in = input;
	this->size = size;


	out697 = new float[size];
	out770 = new float[size];
	out852 = new float[size];
	out941 = new float[size];
	out1209 = new float[size];
	out1336 = new float[size];
	out1477 = new float[size];
	out1633 = new float[size];

	for (int i = 0;  i < size; ++i){
		out697[i] = 0;
		out770[i] = 0;
		out852[i] = 0;
		out941[i] = 0;
		out1209[i] = 0;
		out1336[i] = 0;
		out1477[i] = 0;
		out1633[i] = 0;
	}


}

void FilterAdapter::updateSensitivity(int value)
{
	min_energy = 0.0001 * (10 - float(value));
	cout << "updating sensitivity " << min_energy<< endl;
}

bool FilterAdapter::isRinging()
{
	return RINGING == callState;
}

void FilterAdapter::openCall()
{
	callState = ON_CALLING;
}

bool FilterAdapter::onCall()
{
	return callState == ON_CALLING;
}

void FilterAdapter::exitCall()
{
	callState = OUT_CALL;
}

void FilterAdapter::typingKeys()
{
	callState = TYPING_KEYS;
}

bool FilterAdapter::onTypingKeys()
{
	return callState == TYPING_KEYS;
}

FilterAdapter::~FilterAdapter()
{
	DtmfTone_destroy(f);

}


high_resolution_clock::time_point FilterAdapter::getRingStartTime(){
	return t;
}

void FilterAdapter::setIdle()
{
	callState = IDLE;
}
