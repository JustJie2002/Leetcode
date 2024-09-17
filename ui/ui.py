import itertools
import math
import statistics
import time
import typing
import webbrowser

import matplotlib.figure as figure
import numpy

import tkintertools as tkt
import tkintertools.animation as animation
import tkintertools.color as color
import tkintertools.color.hsl as hsl
import tkintertools.color.rgb as rgb
import tkintertools.core.constants as constants
import tkintertools.standard.dialogs as dialogs
import tkintertools.standard.widgets as widgets
import tkintertools.style as style
import tkintertools.toolbox as toolbox

if toolbox.load_font("./assets/fonts/LXGWWenKai-Regular.ttf"):
    constants.FONT = "LXGWWenKai Regular"

class App(tkt.Tk):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)

        frame_side = tkt.Frame(self, width=320, expand="x")
        frame_side.pack(fill="y", side="left")
        self.frame_main = frame_main = tkt.Frame(self, zoom_item=True)
        frame_main.pack(fill="both", expand=True)

        tkt.Image(frame_main, (480, 240),
                  image=tkt.PhotoImage(file="./assets/logo.png"))

        tkt.Text(frame_main, (480, 360),
                 text="Choose a test,\nAnd just have fun!", fontsize=32, justify="center")

        github = "https://github.com/Xiaokang2022/tkintertools"
        tkt.UnderlineButton(frame_main, (480, 560), text=github,
                            command=lambda: webbrowser.open_new_tab(github))

        self.load_canvas_side(frame_side)

    def load_canvas_side(self, frame: tkt.Frame) -> None:
        canvas = tkt.Canvas(
            frame, expand="y", highlightthickness=0)
        canvas.place(width=320, height=720)
        title = tkt.Text(canvas, (160, 50), text="tkintertools", fontsize=32)
        sub_title = tkt.Text(canvas, (160, 90), text="3.0.0.rc1 (Pre-release)")

        sizes = ((270, 50),)*10
        texts = ("Basic Test", "Window Test", 
                 "Text Test", "Image Test",
                 "Matplotlib Test", "3D Test", "Animation Test", "Dialog Test",
                 "Color Test", "About TKT"
                )
        commands = (
            lambda: BasicestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: WindowTestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: TextTestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: ImageTestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            # lambda: MplTestCanvas(
            #     self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            # lambda: ThreeDTestCanvas(
            #     self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: AnimationTestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: DialogTestCanvas(
                self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            # lambda: ColorTestCanvas(
            #     self.frame_main, zoom_item=True, free_anchor=True, keep_ratio="min", name="Canvas"),
            lambda: tuple(canvas.destroy()
                          for canvas in self.frame_main.canvases),
        )

        tkt.SegmentedButton(canvas, (20, 140), sizes,
                            texts=texts, commands=commands, layout="vertical")

        animation.GradientItem(
            canvas, title._texts[0].items[0], "fill", 2000, ("red", "orange"), controller=lambda p: math.sin(p*math.pi), repeat=-1).start()
        animation.GradientItem(
            canvas, sub_title._texts[0].items[0], "fill", 2000, ("green", "cyan"), controller=lambda p: math.sin(p*math.pi), repeat=-1).start()


class BasicestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        tkt.Button(self, (20, 20), text="Button")
        tkt.Button(self, (20, 80), text="Disabled Button").disabled()

        tkt.Label(self, (220, 20), text="Label")
        tkt.Label(self, (220, 80), text="Disabled Label").disabled()

        tkt.ToggleButton(self, (420, 20), text="ToggleButton")
        tkt.ToggleButton(
            self, (420, 80), text="Disabled ToggleButton").disabled()

        tkt.IconButton(self, (680, 20), text="IconButton",
                       image=tkt.PhotoImage(file="./assets/images/logo.png"))
        tkt.IconButton(self, (680, 80), text="Disabled IconButton",
                       image=tkt.PhotoImage(file="./assets/images/logo.png")).disabled()

        tkt.Switch(self, (20, 200))
        tkt.Switch(self, (20, 260)).disabled()
        tkt.Switch(self, (120, 200), default=True)
        tkt.Switch(self, (120, 260), default=True).disabled()

        tkt.CheckButton(self, (220, 200))
        tkt.CheckButton(self, (220, 260)).disabled()
        tkt.RadioButton(self, (320, 200))
        tkt.RadioButton(self, (320, 260)).disabled()
        tkt.ProgressBar(self, (420, 200)).set(0.5)
        tkt.ProgressBar(self, (420, 260)).disabled()

        tkt.SegmentedButton(self, (20, 360), texts=(
            "Option1", "Option2", "Option3"), default=0)
        tkt.SegmentedButton(self, (20, 440), texts=(
            "Option1", "Option2", "Option3"), default=1).disabled()
        tkt.SegmentedButton(self, (360, 360), layout="vertical", texts=(
            "Option1", "Option2", "Option3"), default=2)
        tkt.SegmentedButton(self, (500, 360), layout="vertical", texts=(
            "Option1", "Option2", "Option3")).disabled()

        widgets.OptionButton(self, (640, 360))
        widgets.ComboBox(self, (640, 440))


class WindowTestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        tkt.Text(self, (20, 20), text="Appearance (Light / Dark)", anchor="nw")
        tkt.Switch(self, (20, 60), default=style.get_color_mode(
        ) == "dark", command=lambda b: style.set_color_mode("dark" if b else "light"))

        tkt.Text(self, (350, 20), text="Style (Win10 / Win11)", anchor="nw")
        tkt.Switch(self, (350, 60), command=lambda b: self.restart(
            "Windows11" if b else "Windows10"), default=constants.SYSTEM == "Windows11")

        tkt.Text(self, (650, 20), text="HideTitleBar (False / True)", anchor="nw")
        tkt.Switch(self, (650, 60), command=lambda b: style.customize_window(
            root, hide_title_bar=b))

        modes = 'Rectangular', 'SmallRound', 'Round'
        commands = [lambda m=m: style.customize_window(
            root, boarder_type=m.lower()) for m in modes]
        tkt.Text(self, (20, 140), text="BoaderType", anchor="nw")
        tkt.SegmentedButton(self, (20, 180), texts=modes,
                            commands=commands, default=2)

        texts = ["All", "MaxMin", "None"]
        commands = [lambda t=t: style.customize_window(
            root, hide_button=t.lower()) for t in texts]
        tkt.Text(self, (500, 140), text="HideTitleBarButton", anchor="nw")
        tkt.SegmentedButton(self, (500, 180), texts=texts,
                            commands=commands, default=2)

        styles = ("normal", "mica", "acrylic", "aero", "transparent",
                  "optimised", "win7", "inverse", "native", "popup")
        commands = [lambda s=s: style.customize_window(
            root, style=s) for s in styles]
        tkt.Text(self, (20, 280),
                 text="Theme (Only Works on Windows OS!)", anchor="nw")
        tkt.SegmentedButton(self, (20, 320), texts=styles, commands=commands)

        t = tkt.Text(self, (20, 420), text="Alpha (100%)", anchor="nw")
        tkt.Slider(self, (20, 460), (350, 30), command=lambda p: (
            t._texts[0].set("Alpha (%d%%)" % (p*100)), root.alpha(p)), default=root.alpha())

        tkt.Text(self, (450, 420), text="DisabledMaxButton", anchor="nw")
        tkt.Switch(self, (450, 460), command=lambda b: style.customize_window(
            root, disable_maximize_button=b))

        tkt.Text(self, (700, 420), text="DisabledMinButton", anchor="nw")
        tkt.Switch(self, (700, 460), command=lambda b: style.customize_window(
            root, disable_minimize_button=b))

    def restart(self, win: typing.Literal["Windows10", "Windows11"]) -> None:
        global root
        root.update_idletasks()
        root.destroy()
        constants.SYSTEM = win
        root = App(title=f"{tkt.__name__} {tkt.__version__} - {constants.SYSTEM}")
        root.center()
        root.mainloop()


class TextTestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        self.create_text(
            20, 20, text="This line of text is not scaled and does not respond to the color theme", anchor="nw", fill="grey")

        tkt.Text(self, (20, 100),
                 text="This is a Text widget that can be scaled and actively responds to the color theme", anchor="nw")

        tkt.Text(self, (20, 200), text="Normal InputBox", anchor="nw")
        tkt.InputBox(self, (20, 240))
        tkt.Text(self, (20, 300), text="Password InputBox", anchor="nw")
        tkt.InputBox(self, (20, 340), show="●")
        tkt.Text(self, (20, 400), text="Placeholder InputBox", anchor="nw")
        tkt.InputBox(self, (20, 440), placeholder="Placeholder")

        tkt.Text(self, (300, 200), text="SpinBox", anchor="nw")
        tkt.SpinBox(self, (300, 240))


class ImageTestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        self.create_text(
            20, 20, text="This image will not be scaled", anchor="nw", fill="grey")
        self.image = tkt.PhotoImage(file="./assets/logo.png")
        self.create_image(20, 60, image=self.image, anchor="nw")

        tkt.Text(self, (20, 260), text="This image can be zoomed", anchor="nw")
        tkt.Image(self, (20+64, 300+64), image=self.image)

        self.scaled_image = self.create_image(660, 200, image=self.image)

        sx = tkt.Slider(self, (460, 420),
                        command=lambda x: self.zoom_image(x, sy.get()))
        sy = tkt.Slider(self, (460, 470),
                        command=lambda y: self.zoom_image(sx.get(), y))

        sx.set(0.5)
        sy.set(0.5)

    def zoom_image(self, x: float, y: float):
        x = (3*x + 1)/2
        y = (3*y + 1)/2
        self.image_copied = self.image.scale(x, y)
        self.itemconfigure(self.scaled_image, image=self.image_copied)



class AnimationTestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        tkt.Text(self, (20, 20), text="Choose a control function", anchor="nw")
        self.s = tkt.SegmentedButton(self, (20, 60), texts=(
            "Flat", "Smooth", "Rebound"), default=0)

        tkt.Text(self, (350, 20), text="Duration (ms)", anchor="nw")
        self.ms = tkt.SpinBox(self, (350, 60))

        tkt.Text(self, (600, 20), text="FPS", anchor="nw")
        self.fps = tkt.SpinBox(self, (600, 60))

        tkt.Button(self, (100, 480), text="Start",
                   command=lambda: self.move_item(False))
        tkt.Button(self, (20, 480), text="Back",
                   command=lambda: self.move_item(True))

        self.item = self.create_oval(
            100, 300, 150, 350, fill="orange", outline="grey")

    def move_item(self, back: bool) -> None:
        func = [animation.flat, animation.smooth,
                animation.rebound][self.s.get()]
        ms = int(self.ms.get())
        fps = int(self.fps.get())
        animation.MoveItem(
            self, self.item, ms, (-500 if back else 500, 0), controller=func, fps=fps).start()


class DialogTestCanvas(tkt.Canvas):

    def __init__(self, master: tkt.Canvas, *args, **kwargs):
        for canvas in master.canvases:
            canvas.destroy()
        super().__init__(master, *args, **kwargs)
        self.place(width=958, height=540, x=481, y=360, anchor="center")

        tkt.Text(self, (20, 20), text="Special Dialogs", anchor="nw")
        tkt.Button(self, (20, 60), text="Color Chooser",
                   command=dialogs.TkColorChooser)
        tkt.Button(self, (200, 60), text="Font Chooser",
                   command=dialogs.TkFontChooser)
        tkt.Button(self, (380, 60), text="Toplevel", command=tkt.Toplevel)
        tkt.Button(self, (500, 60), text="Embed Toplevel",
                   command=lambda: toolbox.embed_window(tkt.Toplevel(size=(480, 360)), self))

        tkt.Text(self, (20, 150), text="Message Box", anchor="nw")

        tkt.Text(self, (20, 200), text="Icon", anchor="nw")
        icons = 'error', 'info', 'question', 'warning'
        s1 = tkt.SegmentedButton(self, (20, 240), default=1, texts=icons)

        tkt.Text(self, (20, 320), text="Type", anchor="nw")
        types = 'abortretryignore', 'ok', 'okcancel', 'retrycancel', 'yesno', 'yesnocancel'
        s2 = tkt.SegmentedButton(self, (20, 360), default=1, texts=types)

        tkt.Button(self, (20, 460), text="Generate Message Box!",
                   command=lambda: dialogs.TkMessage("Message", "Detail", icon=icons[s1.get()], type=types[s2.get()]))


root = App(title=f"{tkt.__name__} {tkt.__version__} - {constants.SYSTEM}")
root.center()
root.mainloop()