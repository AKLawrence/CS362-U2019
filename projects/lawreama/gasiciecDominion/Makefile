CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out




ut1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

ut2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	
ut3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

ut4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

ut5: unittest5.c dominion.o rngs.o
	gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)

ct1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

ct2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	
ct3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	
ct4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	
ct5: cardtest5.c dominion.o rngs.o
	gcc -o cardtest5 -g cardtest5.c dominion.o rngs.o $(CFLAGS)
		
unittestresults: ut1 ut2 ut3 ut4 ut5 ct1 ct2 ct3 ct4 ct5
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./unittest5 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	./cardtest5 >> unittestresult.out
	gcov unittest1.c >> unittestresults.out
	cat unittest1.c.gcov >> unittestresults.out	
	gcov unittest2.c >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	cat cardtest3.c.gcov >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out





rtc1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

rtc2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

rtc3: randomtestcard3.c dominion.o rngs.o
	gcc -o randomtestcard3 -g randomtestcard3.c dominion.o rngs.o $(CFLAGS)

randomtestresults: rtc1 rtc2 rtc3
	./randomtestcard1 &> randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	./randomtestcard3 >> randomtestresults.out
	gcov randomtestcard1.c >> randomtestresults.out
	cat randomtestcard1.c.gcov >> randomtestresults.out	
	gcov randomtestcard2.c >> randomtestresults.out
	cat randomtestcard2.c.gcov >> randomtestresults.out
	gcov randomtestcard3.c >> randomtestresults.out
	cat randomtestcard3.c.gcov >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out




player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out *.exe *.exec testDrawCard testDrawCard.exe randomtestcard1 randomtestcard2 randomtestcard3 unittest1 unittest2 unittest3 unittest4 unittest5 cardtest1 cardtest2 cardtest3 cardtest4 cardtest5
