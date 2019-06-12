#include <iostream>
using namespace std;

class Direction{
public:
    int x=0;
    int y=0;
};

class Player{
public:
    void startGame();  // 开始游戏
    bool isWin(); // 是否赢了
    void move(Direction direction); // 移动
    void printStatus(); // 输出当前状态
    void shuffle();  // 打乱顺序

private:
    int step = 0;
    int currentX=2;
    int currentY=2;
    int nums[3][3] = {1,2,3,4,5,6,7,8,0};
};


void Player::move(Direction direction){
    int targetX = currentX + direction.x;
    int targetY = currentY + direction.y;
    if (!((targetX<3 && targetX>=0)&&(targetY<3&&targetY>=0)))return;

    // 交换(currentX, currentY)和(targetX, targetY)
    int tmp = nums[currentX][currentY];
    nums[currentX][currentY] = nums[targetX][targetY];
    nums[targetX][targetY] = tmp;

    // 更新当前位置信息
    currentX = targetX;
    currentY = targetY;
    step++;

}

bool Player::isWin(){
    int c = 1;
    for (int x = 0;x<3;x++){
        for(int y =0;y<3;y++){
            if(nums[x][y]!=c)return false;
            if(x==2&&y==1)c=0;
            else c++;
        }
    }
    cout << "\n你赢了, 步数：" << step << endl;
    return true;
}

void Player::printStatus() {
    cout << "您已操作了" << step << "步，" << "当前状态: "<< endl;
    cout << nums[0][0] << " " << nums[0][1] << " " << nums[0][2] << endl;
    cout << nums[1][0] << " " << nums[1][1] << " " << nums[1][2] << endl;
    cout << nums[2][0] << " " << nums[2][1] << " " << nums[2][2] << endl;
}


void Player::shuffle()
{
    int length = 3;
    srand(unsigned(time(NULL)));

    for (int x = 0;x<length;x++){
        for(int y = 0;y<length;y++){
            int targetX = rand()%length;
            int targetY = rand()%length;

            // 如果轮到最后一个就直接跳过，打乱顺序的时候不能把最后的0给打乱了
            if((x==2&&y==2)||(targetX==2&&targetY==2))continue;

            // 随机交换位置
            int tmp = nums[x][y];
            nums[x][y] = nums[targetX][targetY];
            nums[targetX][targetY] = tmp;
        }
    }
}

Direction getDirectionFromInput(char dInput){
    Direction direction = Direction();
    switch (dInput){
        case 'w':
            direction.x = -1;
            direction.y = 0;
            break;
        case 's':
            direction.x = 1;
            direction.y = 0;
            break;
        case 'a':
            direction.x = 0;
            direction.y = -1;
            break;
        case 'd':
            direction.x = 0;
            direction.y = 1;
            break;
    }
    return direction;
}

void Player::startGame() {
    shuffle();
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
        if(isWin())break;
        printStatus();
    }
}




int main() {

    Player player;
    player.startGame();
    return 0;
}