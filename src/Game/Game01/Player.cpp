#include "Player.h"
#include "Object.h"
namespace Game01 {

bool Player::Init()
{
    __super::Init();

    SetName("Player");
    SetTranslate({0.0f, 5.0f, 0.0f});

    //Collision
    AddComponent<ComponentCollisionCapsule>()->SetRadius(4.0f)->SetHeight(6.0f)->UseGravity();

    //!!
    auto model = AddComponent<ComponentModel>("data/model/player2/Player2.mv1");
    model->SetAnimation({
        {"idle",       "data/Anims/Idle/Idle.mv1", 0, 1.0f},
        {"walk", "data/Anims/Walking/Walking.mv1", 0, 1.0f},
    });
    model->SetScaleAxisXYZ({0.08f, 0.08f, 0.08f});
    model->SetTranslate({0.0f, 0.0f, 0.0f});
    model->SetRotationAxisXYZ({0.0f, 0.0f, 0.0f});
    model->UseShader(TRUE);

    //move
    AddComponent<ComponentObjectController>()
        ->SetMoveSpeed(0.3f)
        ->SetRotateSpeed(20.0f)
        ->SetKeys(KEY_INPUT_UP, KEY_INPUT_DOWN, KEY_INPUT_LEFT, KEY_INPUT_RIGHT)
        ->SetCameraKeys(KEY_INPUT_W, KEY_INPUT_S, KEY_INPUT_A, KEY_INPUT_D);

    return true;
}

//! @brief 更新
void Player::Update()
{
    // 毎フレーム動作する
    Super::Update();

    //ジャンプ
    if(IsKey(KEY_INPUT_SPACE) && !isJump_) {
        isJump_ = true;
    }

    if(isJump_) {
        jumpPower_ = 0.5f;
        AddTranslate({0, jumpPower_, 0});
    }

    //障害物を持ち上げる
    if(IsKeyOn(KEY_INPUT_X) && !takeMode_) {
        //一番近いストーンを探す
        float                   minDist      = 1000.0f;
        std::shared_ptr<Object> nearestStone = nullptr;

        //全部のストーン
        auto   stoneList = Scene::GetObjectsPtr<Stone>();
        float3 playerPos = GetTranslate();
        float3 wayPos    = {0.0f, 0.0f, 0.0f};

        //全部のストーンとプレーヤーの距離を取る
        for(auto& stone : stoneList) {
            float3 stonePos = stone->GetTranslate();
            float3 dir      = stonePos - playerPos;
            float  dist     = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);

            //プレーヤーの近い一つと持ち上げる範囲内
            if(dist < 10.0f && dist < minDist) {
                minDist      = dist;
                nearestStone = stone;
                wayPos       = stonePos;
            }
        }
        //takenStone_に入れる
        if(nearestStone) {
            takeMode_   = true;
            takenStone_ = nearestStone;

            //!!プレイヤーの向きを変わりたい
            GetComponent<ComponentModel>()->SetRotationToPosition(wayPos);
        }
    }

    if(takeMode_ && takenStone_) {
        //障害物の重力を消す
        takenStone_->GetComponent<ComponentCollisionSphere>()->UseGravity(false);

        float3 stonePos  = takenStone_->GetTranslate();
        float3 playerPos = GetTranslate();

        //プレイヤーと障害物のベクトル
        float3 moveVec = playerPos - stonePos;
        //プレイヤーの上
        moveVec.y += 15.0f;
        //移動量を20％にする
        moveVec *= 0.2f;
        //移動させる
        takenStone_->AddTranslate(moveVec);
    }

    //障害物を投げる
    if(IsKeyOn(KEY_INPUT_C) && takeMode_ && takenStone_) {
        //投げるモードオン
        throwMode_ = true;
        takeMode_  = false;
    }

    if(throwMode_ && takenStone_) {
        auto stone = std::dynamic_pointer_cast<Stone>(takenStone_);
        if(stone) {
            //プレーヤーの方向の計算
            auto model = GetComponent<ComponentModel>();
            auto dir   = model->GetWorldMatrix().axisZ();
            dir.y      = 0.2f;

            ////ストーンに方向を渡す
            stone->SetDirection(dir);
            stone->SetIsFlying(true);

            //重力を元に戻す
            takenStone_->GetComponent<ComponentCollisionSphere>()->UseGravity(true);
            //投げるモードをオフ
            throwMode_  = false;
            takenStone_ = nullptr;
        }
    }
}

void Player::Draw()
{
    Super::Draw();

    //プレイヤー
    //位置
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(255, 255, 255);
    //方向
    auto rot = cast(GetRotationAxisXYZ());
    //描画
    //DrawSphere3D(pos, r_, 20, color, color, TRUE);

    //方向をわかる円
    auto model = GetComponent<ComponentModel>();
    if(!model)
        return;
    //方向
    auto dir = model->GetWorldMatrix().axisZ();

    //auto dir = -model->GetTranslate();

    //プレイヤーと離れる距離
    float offset = 6.0f;
    //位置
    float3 cPos = float3(pos.x + dir.x * offset, pos.y + dir.y * offset, pos.z + dir.z * offset);
    //色
    int cColor = GetColor(0, 255, 255);
    //描画
    DrawSphere3D(cast(cPos), 3.0f, 16, cColor, cColor, TRUE);
}

void Player::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        isJump_    = false;
        jumpPower_ = 0.0f;
    }
}

}    // namespace Game01
