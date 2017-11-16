#include <winsock.h>
#include <cstdio>
#include <iostream>
#include <string>
//to napisa³ marcin
#define MY_PORT 2500

void dodawanie();
void odejmowanie();
void mnozenie();
void dzielenie();
void modulo();
void rownosc();
void potegowanie();
void silnia();
std::string decimalToBinary(int liczba);

//bufor danych do wys³ania w postaci string - segment
std::string buforS;

int main(int argc, char *argv[])
{

	/*strcpy(bufor, "000");
	printf("%s", "Podaj dwie liczby: ");
	char *temp = (char*)malloc(1);
	scanf("%s", temp);
	strcat(bufor, temp);
	std::cout <<  temp << std::endl;*/

	/*char *buffer = (char*)malloc(40);
	char *str = "worfd";
	strcpy(buffer, "ddddd");
	strcpy(&buffer[4], str);
	std::cout << buffer;*/
	/*char *buffer = (char*)malloc(40);
	char *str = "worfd";
	
	strcpy(buffer, str);
	strcat(buffer, str);
	std::cout << buffer;*/
	std::cin.get();
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
	{
		fprintf(stderr, "WSAStartup failed.\n");
		exit(1);
	}

	
	int sockfd; //deskryptor gniazda klienta
	int new_fd;//deskryptor gniazda serwera
	sockfd = socket(PF_INET, SOCK_STREAM, 0);

	
	
	//wczytywanie IP serwera
	char *DEST_IP;
	DEST_IP = (char*)malloc(0); // o co chodzi z t¹ alokacj¹ pamiêci
	printf("%s", "Podaj adres IP: \n");
	//scanf("%s", DEST_IP);
	DEST_IP = "192.168.0.20";

	//wczytywanie portu serwera
	u_short DEST_PORT;
	printf("%s", "Podaj port (3490): \n");
	//std::cin >> DEST_PORT;
	DEST_PORT = 3490;

	sockaddr_in theirAddr;
	theirAddr.sin_family = PF_INET;
	theirAddr.sin_port = htons(DEST_PORT);
	theirAddr.sin_addr.s_addr = inet_addr(DEST_IP);
	memset(&theirAddr.sin_zero, '\0', 8);
	
	//³¹czenie z serwerem
	if (new_fd = connect(sockfd, (struct sockaddr *) & theirAddr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}
	printf("client: got connection to %s\n", inet_ntoa(theirAddr.sin_addr));

	//char* bufor;
	//bufor = (char*)malloc(65354);
	int wybor;
	std::cout << "Operacje:\n";
	std::cout << "1. Dodawanie\n2"; //000
	std::cout << "2. Odejmowanie\n2"; //001
	std::cout << "3. Mnozenie\n2"; //010
	std::cout << "4. Dzielenie\n2"; //011
	std::cout << "5. Modulo\n2"; //100
	std::cout << "6. Rownosc\n2"; //101
	std::cout << "7. Potegowanie\n2"; //110
	std::cout << "8. Silnia\n2"; //111
	
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
		{
			dodawanie();
			break;
		}
		case 2:
		{
			odejmowanie();
			break;
		}
		case 3:
		{
			mnozenie();
			break;
		}
		case 4:
		{
			dzielenie();
			break;
		}
		case 5:
		{
			modulo();
			break;
		}
		case 6:
		{
			rownosc();
			break;
		}
		case 7:
		{
			potegowanie();
			break;
		}
		case 8:
		{
			silnia();
			break;
		}
	}

	
	/*if (send(new_fd, bufor, 65534, 0) == -1)
	{
		perror("send");

		closesocket(new_fd);
		exit(0);
	}*/


	
	std::cin.get();
	
	closesocket(sockfd);

	return 0;
}


void dodawanie()
{
	buforS += "000";
	std::cout << "Podaj dwie liczby do dodania (max 65535): ";
	int l1, l2;
	std::cin >> l1 >> l2;
	if ((l1 || l2) > 65535)
	{
		std::cout << "Liczba zbyt duza. Koniec programu.\n";
		exit(1);
	}
	buforS += decimalToBinary(l1);
	buforS += decimalToBinary(l2);
}
void odejmowanie()
{
	buforS += "001";
	std::cout << "Podaj odjemna i odjemnik: (max 65535): ";
	int l1, l2;
	std::cin >> l1 >> l2;
	if ((l1 || l2) > 65535)
	{
		std::cout << "Liczba zbyt duza. Koniec programu.\n";
		exit(1);
	}
	buforS += decimalToBinary(l1);
	buforS += decimalToBinary(l2);
}
void mnozenie()
{
	buforS += "010";
	std::cout << "Podaj mnozna i mnoznik (max 65535): ";
	int l1, l2;
	std::cin >> l1 >> l2;
	if ((l1 || l2) > 65535)
	{
		std::cout << "Liczba zbyt duza. Koniec programu.\n";
		exit(1);
	}
	buforS += decimalToBinary(l1);
	buforS += decimalToBinary(l2);
}
void dzielenie()
{
	buforS += "011";
	std::cout << "Podaj dzielna i dzielnik (max 65535): ";
	int l1, l2;
	std::cin >> l1 >> l2;
	if ((l1 || l2) > 65535)
	{
		std::cout << "Liczba zbyt duza. Koniec programu.\n";
		exit(1);
	}
	buforS += decimalToBinary(l1);
	buforS += decimalToBinary(l2);
}
void modulo()
{
	buforS += "100";
	std::cout << "JEZUS CO TU NAPISAC (max 65535): ";
	int l1, l2;
	std::cin >> l1 >> l2;
	if ((l1 || l2) > 65535)
	{
		std::cout << "Liczba zbyt duza. Koniec programu.\n";
		exit(1);
	}
	buforS += decimalToBinary(l1);
	buforS += decimalToBinary(l2);
}
void rownosc()
{
	buforS += "101";
}
void potegowanie()
{
	buforS += "110";
}
void silnia()
{
	buforS += "111";
}
std::string decimalToBinary(int liczba)
{
	/*std::stringstream a(liczba);
	int liczbaInt;
	a >> liczbaInt;*/

	if (liczba == 0) return "0";
	if (liczba == 1) return "1";

	if (liczba % 2 == 0)
		return decimalToBinary(liczba / 2) + "0";
	else
		return decimalToBinary(liczba / 2) + "1";
}