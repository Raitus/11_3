#include <iostream>
#include "string"

bool CheckNumber(std::string number) {
  if (number.length()==0 || number.length() > 3) {
	return false;
  } else {
	for (char i : number) {
	  if (i < '0' || i > '9')
		return false;
	}

	if ((number.length()==2 && number[0]=='0')
		|| (number.length()==3 && ((number[0]=='0' && number[1]=='0') || number[0]=='0'))) {
	  return false;
	} else {
	  int numberInt = std::stoi(number);
	  if (numberInt >= 0 && numberInt <= 255) {
		return true;
	  } else {
		return false;
	  }
	}
  }
}

bool IpAddressValidation(std::string ip) {
  std::string number;
  for (int count = 0, dotCount = 0; count < ip.length(); count++) {
	for (; count < ip.length() && ip[count]!='.'; count++) {
	  number += ip[count];
	}
	if (ip[count]=='.')dotCount++;
	if (!CheckNumber(number)) {
	  return false;
	} else if (count==ip.length() && dotCount==3) {
	  return true;
	} else if (dotCount > 3) {
	  return false;
	}
	number = "";
  }
  return false;
}

int main() {
  std::string ipAddress;
  std::cout << "Input IP-address: ";
  std::getline(std::cin, ipAddress);
  if (IpAddressValidation(ipAddress)) {
	std::cout << "Yes!";
  } else {
	std::cout << "No!";
  }
  return 0;
}
