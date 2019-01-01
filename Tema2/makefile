all:	00 01 02 03 04 05 06 07 08 09

00:	01.cpp
	g++ 01.cpp -Wall -fno-elide-constructors -std=c++11 -o 01exe

01:	01b.cpp
	g++ 01b.cpp -Wall -fno-elide-constructors -std=c++11 -o 01bexe

02:	02.cpp
	g++ 02.cpp -Wall -std=c++11 -o 02exe

03:	04.cpp
	g++ 04.cpp -Wall -std=c++11 -o 04exe

04:	06.cpp
	g++ 06.cpp -Wall -std=c++11 -o 06exe

05:	07.cpp
	g++ 07.cpp -Wall -std=c++11 -o 07exe

06:	08.cpp
	g++ 08.cpp -Wall -std=c++11 -o 08exe

07:	09.cpp
	g++ 09.cpp -Wall -std=c++11 -o 09exe

08:	10.cpp
	g++ 10.cpp -Wall -std=c++11 -o 10exe

09:	11.cpp
	g++ 11.cpp -Wall -std=c++11 -o 11exe

.PHONY:	clean

clean:
	-rm -f 01exe 01bexe 02exe 04exe 06exe 07exe 08exe 09exe 10exe 11exe
