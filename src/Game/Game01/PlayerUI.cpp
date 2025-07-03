#include "Player.h"
#include "PlayerUI.h"
namespace Game01 {
bool PlayerUI::Init()
{
    __super::Init();
    m_hpx  = 170.0f;
    m_hpy  = 610.0f;
    m_hpx2 = 270.0f;
    return true;
}
void PlayerUI::Update()
{
    SetHp();
}
void PlayerUI::Draw()
{
    Super::Draw();

    for(int i = 0; i < 4; i++) {
        DrawLineBox(50 + 300 * i, 600, 280 + 300 * i, 680, GetColor(0, 255, 255));

        SetFontSize(40);
        DrawFormatString(50 + 300 * i, 590, GetColor(255, 255, 0), "%dP", i + 1);

        //HPの描画
        DrawTriangleAA(m_hpx + 300.0f * i, m_hpy, m_hpx2 + 300.0f * i, m_hpy, 220.0f + 300.0f * i, 670.0f, GetColor(255, 0, 0), TRUE);

        //HPの外枠の描画
        DrawTriangleAA(170.0f + 300.0f * i, 610.0f, 270.0f + 300.0f * i, 610.0f, 220.0f + 300.0f * i, 670.0f, GetColor(0, 0, 0), FALSE);
    }
}
void PlayerUI::Exit()
{
    Super::Exit();
}
void PlayerUI::GUI()
{
    Super::GUI();
}
void PlayerUI::SetHp()
{
    if(CheckHitKey(KEY_INPUT_UP)) {
        m_hpx -= 0.8f;
        m_hpy--;
        m_hpx2 += 0.8f;
    }
    if(CheckHitKey(KEY_INPUT_DOWN)) {
        m_hpx += 0.8f;
        m_hpy++;
        m_hpx2 -= 0.8f;
    }
    if(m_hpx > 220.0f)
        m_hpx = 220.0f;
    if(m_hpx < 170.0f)
        m_hpx = 170.0f;
    if(m_hpx2 < 220.0f)
        m_hpx2 = 220.0f;
    if(m_hpx2 > 270.0f)
        m_hpx2 = 270.0f;
    if(m_hpy > 670.0f)
        m_hpy = 670.0f;
    if(m_hpy < 610.0f)
        m_hpy = 610.0f;
}
void PlayerUI::SetMp()
{
}
}    // namespace Game01
