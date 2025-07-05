#pragma once
#include <System/Scene.h>
namespace Game01 {
USING_PTR(PlayerUI);
//! @brief チュートリアルシーン
class PlayerUI : public Object
{
public:
    BP_OBJECT_DECL(PlayerUI, u8"Game01のPlayerUI");

    //! @brief 初期化
    //! @return 初期化済み
    bool Init() override;
    void Update() override;
    void Draw() override;
    void Exit() override;
    void GUI() override;
    //!HPの増減の処理
    void SetHp();
    //!MPの増減の処理
    void SetMp();

private:
    // 必要であれば変数をここに追加する
    //hpの座標の変数
    //y座標
    float m_hpy[4];
    //左側のx座標
    float m_hpx[4];
    //右側のx座標
    float m_hpx2[4];
    //座標用の変数
    float m_mpx[4];

    //点滅用の変数
    float mp_alpha;
    int   alpha_mode;
    enum
    {
        MODE_IN,
        MODE_OUT,
    };
};
}    // namespace Game01

// namespace Game01
