#include "Ufo.h"
namespace Game01 {
bool Ufo::Init()
{
    __super::Init();
    SetName("Ufo");
    SetTranslate({0.0f, 10.0f, 0.0f});
    return true;
}
void Ufo::Update()
{
    Super::Update();
}

void Ufo::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //Ufoの色
    auto color = GetColor(255, 255, 255);
    //描画[

    for(int i = 1; i < 4; i++) {
        DrawTriangle3D(VGet(5.0f, 10.0f + 5.0 * i, 5.0f), VGet(5.0f, 10.0f + 5.0 * i, 0.0f), VGet(0.0f, 10.0f + 5.0 * i, 5.0f), GetColor(255, 255, 255), TRUE);
    }
}

}    // namespace Game01
