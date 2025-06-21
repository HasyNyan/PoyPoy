#include "Player.h"
#include "PlayerUI.h"
namespace Game01 {
bool PlayerUI::Init()
{
    return true;
}
void PlayerUI::Update()
{
}
void PlayerUI::Draw()
{
    // とりあえずTitleという文字を表示しておく
    DrawFormatString(100, 50, GetColor(255, 255, 255), "テスト");
}
void PlayerUI::Exit()
{
}
void PlayerUI::GUI()
{
}
}    // namespace Game01
