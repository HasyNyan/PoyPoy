#include "Ufo.h"
#include "Object.h"
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

    // auto obj       = Scene::Object::Create<Ufo>();
    // auto transform = obj->GetComponent<ComponentTransform>();
    // float3 rot = {0, 1, 0};
    // transform->AddRotationAxisXYZ(rot);

    float3 pos = GetTranslate();
    if(playMode_ == CREATE)    //生成器の状態がオブジェクト生成モードだったら
    {
        float3 dir = targetPos_ - pos;    //生成器から目的地までのベクトルを作成
        //transform -> AddTranslate(dir, true);                 //作ったベクトルを足す
        Scene::Object::Create<Stone>();    //オブジェクト生成
        playMode_ = MOVE;                  //移動モードに
    }
    if(playMode_ == MOVE)    //生成器の状態がオブジェクト移動モードだったら
    {
        stayTime_++;
        if(stayTime_ >= 600) {
            targetPos_ = {GetRand(50.0f) + 20.0f, 0.0f, GetRand(50.0f) + 20.0f};    //目的地をランダムに変更
            stayTime_  = 0;
            playMode_  = CREATE;
        }
    }
}

void Ufo::Draw()
{
    Super::Draw();
    //描画する位置を取得
    float3 pos = GetTranslate();
    //Ufoの色
    auto color = GetColor(255, 255, 255);
    //右側三角形の頂点
    auto r1 = pos + float3(5.0f, 15.0f, 5.0f);
    auto r2 = pos + float3(5.0f, 15.0f, 0.0f);
    auto r3 = pos + float3(0.0f, 15.0f, 5.0f);
    //左側三角形の頂点
    auto l1 = pos + float3(0.0f, 15.0f, 0.0f);
    auto l2 = pos + float3(5.0f, 15.0f, 0.0f);
    auto l3 = pos + float3(0.0f, 15.0f, 5.0f);
    //描画
    //DrawTriangle3D(VGet(5.0f, 15.0f, 5.0f), VGet(5.0f, 15.0f, 0.0f), VGet(0.0f, 15.0f, 5.0f), GetColor(255, 255, 255), TRUE);    //右側の三角形
    //DrawTriangle3D(VGet(0.0f, 15.0f, 0.0f), VGet(5.0f, 15.0f, 0.0f), VGet(0.0f, 15.0f, 5.0f), GetColor(255, 255, 255), TRUE);    //左側の三角形
    DrawTriangle3D(cast(r1), cast(r2), cast(r3), GetColor(255, 255, 255), TRUE);    //右側の三角形
    DrawTriangle3D(cast(l1), cast(l2), cast(l3), GetColor(255, 255, 255), TRUE);
}

}    // namespace Game01
