#include "Player.h"
#include "PlayerUI.h"
namespace Game01 {
bool PlayerUI::Init()
{
    __super::Init();
    return true;
}
void PlayerUI::Update()
{
}
void PlayerUI::Draw()
{
    Super::Draw();

    for(int i = 0; i < 4; i++) {
        DrawLineBox(50 + 300 * i, 600, 280 + 300 * i, 680, GetColor(0, 255, 255));

        SetFontSize(40);
        DrawFormatString(50 + 300 * i, 590, GetColor(255, 255, 0), "%dP", i + 1);

        DrawTriangleAA(170.0f + 300.0f * i, 610.0f, 270.0f + 300.0f * i, 610.0f, 220.0f + 300.0f * i, 670.0f, GetColor(0, 0, 0), FALSE);
    }
}
void PlayerUI::Exit()
{
    Super::Exit();
}
void PlayerUI::GUI()
{
}
}    // namespace Game01
