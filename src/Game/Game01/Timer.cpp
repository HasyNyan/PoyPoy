#include "Timer.h"    //　必須
namespace Game01 {

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
bool Timer::Init()
{
    Super::Init();

    Timer_Imēji = LoadGraph("data/UI/Timr.png");      // 画像読み込み
    GetGraphSize(Timer_Imēji, &Timer_x, &Timer_y);    // 画像の横幅のピクセル数を取得
    SetFontSize(50);                                  // タイマーのサイズ
    startTime = GetNowCount();                        // 開始時間（ミリ秒単位）を記録

    return true;    //boolの返すリターン
}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// ======================================================
void Timer::Update()
{
    Super::Update();
}
// =====================================================
//		描画
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	GameUpdate関数が実行された後に実行される関数
// =====================================================
void Timer::Draw()
{
    Super::Draw();

    DrawExtendGraph(10, 20, Timer_x / 6, Timer_y / 5, Timer_Imēji, TRUE);    // タイマー本体

    // 現在の経過時間を取得
    int now = GetNowCount();

    // 経過秒数 = (現在の時間 - 開始時間) ÷ 1000（ミリ秒→秒へ変換）
    int elapsedSec = (now - startTime) / 1000;

    // 残り秒数 = 300秒 - 経過秒
    int remainSec = countdownSec - elapsedSec;

    // タイマー終了判定
    if(remainSec <= 0) {
        isFinished = true;
        remainSec  = 0;    // マイナス表示にならないよう0に固定
    }

    // 残り時間を「分」「秒」に分割
    int min = remainSec / 60;
    int sec = remainSec % 60;

    // 画面に時間を表示
    if(!isFinished) {
        // 残り時間の表示
        DrawFormatString(25.5, 30, GetColor(255, 255, 255), "%02d:%02d", min, sec);
    }
    else {
        // タイムアップ時の表示（赤色）
        DrawFormatString(560, 340, GetColor(255, 0, 0), "タイムアップ！");
    }
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void Timer::Exit()
{
    Super::Exit();
    DeleteGraph(Timer_Imēji);
}
}    // namespace Game01
