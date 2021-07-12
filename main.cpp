#include <iostream>
#include "string"

bool checkNumber(std::string number) {
  if (number.length()==0 || number.length() > 3) {
	return false;
  } else {
	int numberInt = 0;
	for (int i = number.length() - 1, coefficient = 1; i >= 0; i--) {
	  if (number[i] >= '0' && number[i] <= '9') {
		numberInt += (number[i] - '0')*coefficient;
		if (i==2 && number[1]=='0' && number[0]=='0'||i==1 && number[0]=='0') {
		  return false;
		}
	  } else {
		return false;
	  }
	  coefficient *= 10;
	}
	if (numberInt >= 0 && numberInt <= 255) {
	  return true;
	} else {
	  return false;
	}
  }
}
void ipAddressValidation(std::string ip) {
  std::string number;
  for (int count = 0, dotCount = 0; count < ip.length(); count++) {
	for (; count < ip.length() && ip[count]!='.'; count++) {
	  number += ip[count];
	}
	if (ip[count]=='.')dotCount++;
	if (!checkNumber(number)) {
	  std::cout << "No!";
	  break;
	} else if (count==ip.length() && dotCount==3) {
	  std::cout << "Yes!";
	}else if (dotCount>3){
	  std::cout << "No!";
	  break;
	}
	number = "";
  }
}
int main() {
  std::string ipAddress;
  std::cout << "Input IP-address: ";
  std::getline(std::cin, ipAddress);
  ipAddressValidation(ipAddress);
  return 0;
}
