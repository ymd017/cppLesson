import maya.api.OpenMaya as om
import maya.cmds as cmds

def create_child_joints(joint_count):
    # 現在選択されているジョイントを取得
    selection = cmds.ls(selection=True, type="joint")

    # ジョイントが選択されていない場合はエラー
    if not selection:
        om.MGlobal.displayError("ジョイントを選択してください")
        return
    
    parent_joint = selection[0]  # 最初に選択されたジョイントを親とする

    if joint_count < 1:
        om.MGlobal.displayError("作成するジョイントの数は1以上にしてください")
        return

    joint_list = []

    for i in range(joint_count):
        cmds.select(clear=True)  # カレントジョイントの影響を防ぐ

        # 新しいジョイントを作成（親の位置に対してY軸方向にずらす）
        parent_pos = cmds.xform(parent_joint, query=True, translation=True, worldSpace=True)
        new_pos = (parent_pos[0], parent_pos[1] + (i + 1) * 5, parent_pos[2])  # 5単位ずつ上に配置
        
        joint_name = cmds.joint(name=f"{parent_joint}_child{i+1}", position=new_pos)
        
        # 親子関係を設定
        cmds.parent(joint_name, parent_joint)

        parent_joint = joint_name  # 作成したジョイントを次の親に設定
        joint_list.append(joint_name)

    om.MGlobal.displayInfo(f"{joint_count} 個のジョイントを {selection[0]} の子として作成しました")

# ユーザー入力
try:
    count = int(input("作成する子のジョイントの数を入力してください： "))
    create_child_joints(count)
except ValueError:
    om.MGlobal.displayError("正しい数値を入力してください")
