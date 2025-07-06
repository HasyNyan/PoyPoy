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
    //描画
    DrawTriangle3D(VGet(5.0f, 15.0f, 5.0f), VGet(5.0f, 15.0f, 0.0f), VGet(0.0f, 15.0f, 5.0f), GetColor(255, 255, 255), TRUE);    //右側の三角形
    DrawTriangle3D(VGet(0.0f, 15.0f, 0.0f), VGet(5.0f, 15.0f, 0.0f), VGet(0.0f, 15.0f, 5.0f), GetColor(255, 255, 255), TRUE);    //左側の三角形
}

}    // namespace Game01
