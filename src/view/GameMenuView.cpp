///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-04 10:39
/// @Mail		: 3453851623@qq.com
/// @brief		: 
///****************************************************************************

#include "GameMenuView.h"

GameMenuView* GameMenuView::s_instance = nullptr;

GameMenuView* GameMenuView::getInstance()
{
    if (!s_instance) {
        s_instance = new GameMenuView();
    }
    return s_instance;
}

GameMenuView::GameMenuView()
{
    m_pGameMainView = nullptr;
}

GameMenuView::~GameMenuView()
{
}

void GameMenuView::showEntryAnimation()
{
    // 播放打字音效
    SoundController::getInstance()->playSound(1001);
    // 故事内容
    vector<string> sentences = {
        "**********************************************************************************",
        "                               都市浮生日记的故事",
        "**********************************************************************************",
        "    您扮演一位从外地到城市谋生的青年，一开始您只有2000元，并且还欠村长（一个流氓头",
        "子）5500元的债务。这些债务每天的利息高达10%，如果不及时还清，村长会叫在市里的老乡们",
        "来扁您，您可能会牺牲在市区街头。您决定在市区地铁各黑市倒卖各种物品来发财致富，不仅还",
        "掉债务而且还要荣登富人排行榜。",
        "    您只能在城市呆100天，每次奔走一个黑市算1天，刚开始您租的房子只能放100个东西。您",
        "会在市区遭遇到各种事件、您需要与流氓、小偷、凶手、贪官、骗子等斗智斗勇，还需要在市区",
        "恶劣的自然环境下设法生存下来。",
        "    您将体验在城市卖盗版VCD和走私汽车的刺激、以及我们这个时代才有的搞笑事件。     ",
        "**********************************************************************************"
    };
    for (int i = 0; i < sentences.size(); ++i) {
        // 播放打字动画效果
        if (i < 3 || i == (sentences.size() - 1)) {
            cout << sentences[i] << endl;
        } else {
            playTypeWrite(sentences[i]);
        }
    }
    // 停止播放打字音效
    SoundController::getInstance()->stopSound(1001);
}

void GameMenuView::playTypeWrite(string line)
{
    int speed = 10; // ms
    for (int i = 0; i < line.length(); ++i) {
        cout << line[i];
        if (line[i] == ' ') {
            continue;
        } else {
            Sleep(speed);
        }
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 主菜单显示
void GameMenuView::showMenu()
{
    string menuName = "欢迎来到《都市浮生日记》！";
    vector<string> itemNames;
    itemNames.push_back("游戏菜单");
    itemNames.push_back("场景选择");
    itemNames.push_back("游戏帮助");
    switch (chooseItemInMenu(menuName, itemNames))
    {
    case 1:
        showGameMenu();     // 游戏菜单
        break;
    case 2:
        showSceneMenu();    // 场景选择
        break;
    case 3:
        showHelpMenu();     // 游戏帮助
        break;
    default:
        cout << "输入有误请重新选择!~";
        Sleep(1000);
        system("cls");
        showMenu();
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 主菜单->游戏菜单
void GameMenuView::showGameMenu()
{
    system("cls");
    string menuName = "主菜单->游戏菜单";
    vector<string> itemNames;
    itemNames.push_back("新游戏");
    itemNames.push_back("高手排行榜");
    itemNames.push_back("游戏设置");
    itemNames.push_back("返回");
    switch (chooseItemInMenu(menuName, itemNames))
    {
    case 1:
        // 新游戏
        GameCore::getInstance()->start();
        break;
    case 2:
        // 高手排行榜
        showGameRank();
        break;
    case 3:
        // 游戏设置
        showGameSetting();
        break;
    case 4:
        // 返回
        system("cls");
        showMenu();
        break;
    default:
        cout << "输入有误请重新选择!~";
        Sleep(1000);
        system("cls");
        showGameMenu();
        break;
    }
}

void GameMenuView::showGameRank()
{

}

void GameMenuView::showGameSetting()
{
    SoundController* sdctl = SoundController::getInstance();
    bool slience = sdctl->getSlience();

    system("cls");
    string menuName = "主菜单->游戏菜单->游戏设置";
    vector<string> itemNames;
    if (slience) {
        itemNames.push_back("开启音效");
    } else {
        itemNames.push_back("关闭音效");
    }
    itemNames.push_back("允许黑客攻击银行网络");
    itemNames.push_back("返回");
    switch (chooseItemInMenu(menuName, itemNames))
    {
    case 1:
        // 音效设置
        sdctl->setSlience(!slience);
        // 执行音效操作
        if (slience) {
            sdctl->playBGM();
        } else {
            sdctl->stopAll();
        }
        showGameSetting();
        break;
    case 2: 
        // 允许黑客攻击银行网络
        break;
    case 3:
        // 返回
        system("cls");
        showGameMenu();
        break;
    default:
        cout << "输入有误请重新选择!~";
        Sleep(1000);
        showGameSetting();
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 主菜单->场景选择
void GameMenuView::showSceneMenu()
{
    string menuName = "主菜单->场景菜单";
    vector<string> itemNames;
    itemNames.push_back("新游戏");
    itemNames.push_back("高手排行榜");
    itemNames.push_back("游戏设置");
    itemNames.push_back("退出游戏");
    switch (chooseItemInMenu(menuName, itemNames))
    {
    case 1:
        // 新游戏
        break;
    case 2:
        // 高手排行榜
        break;
    case 3:
        // 游戏设置
        break;
    case 4:
        // 退出游戏
        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 主菜单->帮助
void GameMenuView::showHelpMenu()
{
    string menuName = "主菜单->帮助菜单";
    vector<string> itemNames;
    itemNames.push_back("新游戏");
    itemNames.push_back("高手排行榜");
    itemNames.push_back("游戏设置");
    itemNames.push_back("退出游戏");
    switch (chooseItemInMenu(menuName, itemNames))
    {
    case 1:
        // 新游戏

        break;
    case 2:
        // 高手排行榜
        break;
    case 3:
        // 游戏设置
        break;
    case 4:
        // 退出游戏
        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GameMenuView::chooseItemInMenu(string menuName, vector<string> itemNames)
{
    // 菜单名称
    cout << menuName << endl;
    for (int i = 0; i < itemNames.size(); ++i) {
        cout << i + 1 << "." << itemNames[i] << endl;
    }
    cout << "请做出你的选择：";
    int opt;
    cin >> opt;
    return opt;
}

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 游戏相关

void GameMenuView::EnterGameMainView()
{
    // 显示游戏主界面
    if (!m_pGameMainView) {
        m_pGameMainView = new GameMainView();
    }
    m_pGameMainView->show();
}

void GameMenuView::EnterGameFinishView()
{
    // 游戏评价显示


}
