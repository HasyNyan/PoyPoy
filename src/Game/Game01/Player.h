#pragma once
#include <System/Scene.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
#include <System/Component/ComponentObjectController.h>
#include <System/Component/ComponentCollisionSphere.h>
namespace Game01 {

USING_PTR(Player);

class Player : public Object
{
public:
    BP_OBJECT_DECL(Player, u8"Game01のPlayer");

    bool Init() override;

    //! @brief 更新
    void Update() override;
    void Draw() override;
    void OnHit(const ComponentCollision::HitInfo& hit_info) override;

private:
    float                   jumpPower_  = 0.5f;
    bool                    isJump_     = false;
    bool                    takeMode_   = false;
    bool                    throwMode_  = false;
    std::shared_ptr<Object> takenStone_ = nullptr;
};

}    // namespace Game01
