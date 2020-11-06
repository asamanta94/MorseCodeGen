CC=g++
OUT=morse

morse: MorseCode.cpp
	$(CC) -o $(OUT) MorseCode.cpp

clean:
	rm -rf $(OUT)
