#include <iostream>
using namespace std;

class Direction{
public:
    int x=0;
    int y=0;
};

class Player{
public:
    void startGame();
    void isWin();
    void move(Direction direction);
    void printStatus();
    void shuffle();

    int step;
    int currentPosition = 8;
    int nums[9] = {1,2,3,4,5,6,7,8,0};
};


void Player::move(Direction direction){
    int tmp = currentPosition;
    if(direction.x == 1 && direction.y == 0 && currentPosition != 2 && currentPosition != 5 && currentPosition != 8){
        currentPosition += 1;
        step ++;
    }else if(direction.x == -1 && direction.y == 0 && currentPosition != 0 && currentPosition != 3 && currentPosition != 6){
        currentPosition -= 1;
        step ++;
    }
    else if(direction.x == 0 && direction.y == -1 && currentPosition != 0 && currentPosition != 1 &&currentPosition !=2){
        currentPosition -= 3;
        step ++;
    }
    else if(direction.x == 0 && direction.y == 1 && currentPosition != 6 && currentPosition != 7 && currentPosition != 8){
        currentPosition += 3;
        step ++;
    }
    nums[tmp] = nums[currentPosition];
    nums[currentPosition] = 0;
}

void Player::isWin(){
    int i = 0;
    for (;i<8;i++){
        if(nums[i] != (i+1))return;
    }
    cout << "\n你赢了, 步数：" << step << endl;
}

void Player::printStatus() {
    cout << "您已操作了" << step << "步，" << "当前状态: " << endl;
    cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    cout << nums[3] << " " << nums[4] << " " << nums[5] << endl;
    cout << nums[6] << " " << nums[7] << " " << nums[8] << endl;
}
void Player::shuffle()
{
    int length = 8;

    int i = 0;
    srand(unsigned(time(NULL)));
    for (;i<length;i++){
        int target = rand()%length;
        int tmp = nums[target];
        nums[target] = nums[i];
        nums[i] = tmp;
    }
}

Direction getDirectionFromInput(char dInput){
    Direction direction = Direction();
    switch (dInput){
        case 'w':
            direction.x = 0;
            direction.y = -1;
            break;
        case 's':
            direction.x = 0;
            direction.y = 1;
            break;
        case 'a':
            direction.x = -1;
            direction.y = 0;
            break;
        case 'd':
            direction.x = 1;
            direction.y = 0;
            break;
    }
    return direction;
}

void Player::startGame() {
//    shuffle();
    cout << "游戏开始，w上 s下 a左 d右 n退出游戏" << endl;
    printStatus();
    Direction direction;
    char dInput;
    while(true){
        cin >> dInput;
        if(dInput == 'n'){
            isWin();
            break;
        }
        direction = getDirectionFromInput(dInput);
        move(direction);
        printStatus();
    }
}




int main() {

    Player player;
    player.startGame();
//    cout << player.nums[0] << endl;
    return 0;
}