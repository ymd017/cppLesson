import maya.api.OpenMaya as om
import maya.cmds as cmds
# ジョイントを作成する
def create_joint_chain(joint_count):
    # ジョイントが２つ以上ないときは警告を出して、処理を終了する
    if joint_count < 1:
        om.MGlobal.displayError("ジョイントの数は1以上にしてください");
        return
    # 変数宣言部
    parent_joint = None
    #ジョイントカウントの数だけ、ジョイントを作成する
    for i in range(joint_count):
        # カレントディレクトリの影響をなくす
        cmds.select(clear=True)
        # ジョイントの作成
        joint_name = cmds.joint(name=f"joint{i+1}", position=(0,i*5,0))
        # 親子関係の設定
        if parent_joint:
            cmds.parent(joint_name, parent_joint)
        # 現在のジョイントを次の親に設定する    
        parent_joint = joint_name
    om.MGlobal.displayInfo(f"{joint_count}個のジョイントを作成しました。\n")
try:
    count = int(input("作成するジョイントの数を入力してください： "))
    create_joint_chain(count)
except ValueError:
    om.MGlobal.displayError("正しい数値を入力してください\n")
