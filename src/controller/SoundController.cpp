///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "SoundController.h"

SoundController* SoundController::s_instance = nullptr;

SoundController* SoundController::getInstance()
{
    if (!s_instance) {
        s_instance = new SoundController();
    }
    return s_instance;
}

SoundController::SoundController()
{
}

SoundController::~SoundController()
{
}

void SoundController::playSound(int id)
{
    /*
        mci 媒体控制接口 播放MPEG AVI MP3 和 ID等
        mciSendString(LPCWSTR lpszCommand, LPWSTR lpszReturnString, UNIT cchReturn, HANDLE hwndCallback)
        参数1：LPCWSTR lpszCommand         命令字符串：如 open、play 、close等
        参数2：LPTSTR lpszReturnString     接受返回信息的字符串 ，即字符串
        参数3：UINT cchReturn              返回字符串的大小，sizeof
        参数4：HANDLE hwndCallback         回调窗口句柄，一般设置为NULL
    */
    stringstream ss;
    ss << "play res/";
    ss << id;
    ss << ".mp3";
    mciSendStringA(ss.str().c_str(), 0, 0, NULL);
}

void SoundController::stopSound(int id)
{
    stringstream ss;
    ss << "stop res/";
    ss << id;
    ss << ".mp3";
    mciSendStringA(ss.str().c_str(), 0, 0, NULL);
}

void SoundController::playBGM()
{
    /*
        PlaySound是Windows用于播放音乐的API函数 只能播放.wav格式的音频
        参数1：要播放声音的字符串（音频文件路径）
        参数2：应用程序的实例句柄 NULL
        参数3：标志组合
            SND_ASYNC       异步方式播放
            SND_FILENAME    指定WAVE文件名
            SND_LOOP        重复播放声音
            直接传入空字符串表示停止播放
    */
    PlaySound(TEXT("res/bgm.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);
}
