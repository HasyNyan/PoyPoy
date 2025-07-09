#pragma once
#include <System/Scene.h>
namespace Game01 {

USING_PTR(Timer);

class Timer : public Object
{
public:
    BP_OBJECT_DECL(Timer, u8"Game01のTimer");

    //  bool Init() override;

    //! @brief 更新
    bool Init() override;
    void Update() override;
    void Draw() override;
    void Exit() override;

    // =====================================================
    //	タイマー
    // =====================================================
    int Timer_Imēji;    // タイマー本体
    int Timer_x;        // タイマーのサイズX
    int Timer_y;        // タイマーのサイズy

    int       startTime    = 0;        // 開始時の時間（ミリ秒）
    const int countdownSec = 120;      // カウントダウン
    bool      isFinished   = false;    // タイマーが終了したかどうかを判定するフラグ
};

}    // namespace Game01
