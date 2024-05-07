import os

import prairielearn as pl

class RectangleExtension(pl.BaseElement):
    def generate(self, data):
        color = pl.get_color_attrib(el, "color", "black")
        stroke_color = pl.get_color_attrib(el, "stroke-color", "black")
        return {
            "left": pl.get_float_attrib(self, "x1", 20),
            "top": pl.get_float_attrib(self, "y1", 20),
            "width": pl.get_float_attrib(self, "width", 100),
            "height": pl.get_float_attrib(self, "height", 40),
            "angle": pl.get_float_attrib(el, "angle", drawing_defaults["angle"]),
            "originX": "center",
            "originY": "center",
            "opacity": pl.get_float_attrib(el, "opacity", drawing_defaults["opacity"]),
            "fill": color,
            "stroke": stroke_color,
            "strokeWidth": pl.get_float_attrib(
                el, "stroke-width", drawing_defaults["stroke-width"] / 2
            ),
            "strokeUniform": True,
            # Will allow the custom attribute to be editable transforming to a textbox
            "editable": True
        }
    
    def is_gradeable():
        return True
    
    def grade():
        return 0
    
    def get_attributes():
        return ["x1", "y1", "width", "height", "angle", "originX", "originY", "opacity","color", "stroke-color", "stroke-width"]
    