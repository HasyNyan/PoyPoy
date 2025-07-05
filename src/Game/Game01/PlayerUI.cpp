#include "Player.h"
#include "PlayerUI.h"
namespace Game01 {
bool PlayerUI::Init()
{
    __super::Init();
    for(int i = 0; i < 4; i++) {
        m_hpx[i]  = 170.0f;
        m_hpy[i]  = 610.0f;
        m_hpx2[i] = 270.0f;
        m_mpx[i]  = 280.0f;
    }
    mp_alpha   = 255.0f;
    alpha_mode = MODE_OUT;
    return true;
}
void PlayerUI::Update()
{
    SetHp();
    SetMp();
    switch(alpha_mode) {
    case MODE_IN:
        mp_alpha += 5.0f;
        if(mp_alpha >= 255.0f) {
            mp_alpha   = 255.0f;
            alpha_mode = MODE_OUT;
        }
        break;
    case MODE_OUT:
        mp_alpha -= 5.0f;
        if(mp_alpha <= 0.0f) {
            mp_alpha   = 0.0f;
            alpha_mode = MODE_IN;
        }
        break;
    }
}
void PlayerUI::Draw()
{
    Super::Draw();

    for(int i = 0; i < 4; i++) {
        DrawLineBox(50 + 300 * i, 600, 280 + 300 * i, 680, GetColor(0, 255, 255));

        SetFontSize(40);
        DrawFormatString(50 + 300 * i, 590, GetColor(255, 255, 0), "%dP", i + 1);

        //HPの描画
        DrawTriangleAA(m_hpx[i] + 300.0f * i, m_hpy[i], m_hpx2[i] + 300.0f * i, m_hpy[i], 220.0f + 300.0f * i, 670.0f, GetColor(255, 0, 0), TRUE);

        //HPの外枠の描画
        DrawTriangleAA(170.0f + 300.0f * i, 610.0f, 270.0f + 300.0f * i, 610.0f, 220.0f + 300.0f * i, 670.0f, GetColor(0, 0, 0), FALSE);

        //MPの描画
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, mp_alpha);
        DrawFillBox(80 + 300 * i, 680, m_mpx[i] + 300 * i, 690, GetColor(0, 255, 0));
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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
    for(int i = 0; i < 4; i++) {
        if(CheckHitKey(KEY_INPUT_UP)) {
            m_hpx[i] -= 0.8f;
            m_hpy[i]--;
            m_hpx2[i] += 0.8f;
        }
        if(CheckHitKey(KEY_INPUT_DOWN)) {
            m_hpx[i] += 0.8f;
            m_hpy[i]++;
            m_hpx2[i] -= 0.8f;
        }
        if(m_hpx[i] > 220.0f)
            m_hpx[i] = 220.0f;
        if(m_hpx[i] < 170.0f)
            m_hpx[i] = 170.0f;
        if(m_hpx2[i] < 220.0f)
            m_hpx2[i] = 220.0f;
        if(m_hpx2[i] > 270.0f)
            m_hpx2[i] = 270.0f;
        if(m_hpy[i] > 670.0f)
            m_hpy[i] = 670.0f;
        if(m_hpy[i] < 610.0f)
            m_hpy[i] = 610.0f;
    }
}
void PlayerUI::SetMp()
{
    for(int i = 0; i < 4; i++) {
        if(CheckHitKey(KEY_INPUT_LEFT)) {
            m_mpx[i]--;
        }
        if(CheckHitKey(KEY_INPUT_RIGHT)) {
            m_mpx[i]++;
        }
        if(m_mpx[i] < 80)
            m_mpx[i] = 80;
        if(m_mpx[i] > 280)
            m_mpx[i] = 280;
    }
}
}    // namespace Game01
