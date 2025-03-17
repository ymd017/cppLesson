import maya.api.OpenMaya as om
import maya.api.OpenMayaUI as omui  # Maya 2025 の UI API
import maya.cmds as cmds
from PySide6.QtGui import QCursor

def create_polyCube_at_cursor():
    view = omui.M3dView.active3dView()
    point = om.MPoint()
    direction = om.MVector()

    # PySide6 を使ってマウスのスクリーン位置を取得
    pos = QCursor.pos()

    # Maya のウィンドウ座標に変換
    screen_x = pos.x()
    screen_y = pos.y()

    # 2D スクリーン座標を 3D ワールド座標に変換
    view.viewToWorld(int(screen_x), int(screen_y), point, direction)

    if direction.y != 0:
        t = -point.y / direction.y
        world_x = point.x + t * direction.x
        world_z = point.z + t * direction.z
    else:
        world_x = point.x
        world_z = point.z

    # キューブを作成して配置
    cube = cmds.polyCube()[0]
    cmds.move(world_x, 0, world_z, cube)

# 実行
create_polyCube_at_cursor()
