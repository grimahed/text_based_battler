# This is meant to be a text based rpg battler, as the name implies It's going to read similar to a battle log, if I had to put a descriptor. You name you character, choose a zone, kill stuff (with abilities you choose from) until you can fight the big bad at X level in Y zone, you win. You can select to flat continue without healing if you're feeling frisky, heal and continue, heal and swap to another zone, unlock a new zone and the most dangerous mob in said zone at said level. Enemies level with you. Feel free to clone whatever is best suited for your needs, just make sure you have a compiler suited for running this. It's in C++20 and C17. Constructed with WSL2 and Ubuntu.

Commands I used to run/test/compile. w/e:
g++ -std=c++20 main.cpp -o battler
./battler
