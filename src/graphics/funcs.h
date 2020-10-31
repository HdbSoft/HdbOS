#ifndef HDBUI_FUNCS_H
#define HDBUI_FUNCS_H

Ui16 GetBoxDrawChar(Ui8 chn, Ui8 fore_color, Ui8 back_color) {
    Ui16 ax = 0;
    Ui8  ah = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    ax |= chn;

    return ax;
}

void DrawSimpleBox(Ui16 x, Ui16 y,
    Ui16 width, Ui16 height,
    Ui8 fore_color, Ui8 back_color,
    Ui8 topleft_ch,
    Ui8 topbottom_ch,
    Ui8 topright_ch,
    Ui8 leftrightside_ch,
    Ui8 bottomleft_ch,
    Ui8 bottomright_ch)
{
    Ui32 i;

    vga_index = 80 * y;
    vga_index += x;

    vga_buffer[vga_index] = GetBoxDrawChar(topleft_ch, fore_color, back_color);

    vga_index++;

    for (i = 0; i < width; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(topbottom_ch, fore_color, back_color);
        vga_index++;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(topright_ch, fore_color, back_color);

    y++;

    vga_index = 80 * y;
    vga_index += x;

    for (i = 0; i < height; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(leftrightside_ch, fore_color, back_color);
        vga_index++;

        vga_index += width;
        vga_buffer[vga_index] = GetBoxDrawChar(leftrightside_ch, fore_color, back_color);

        y++;
        vga_index = 80 * y;
        vga_index += x;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(bottomleft_ch, fore_color, back_color);
    vga_index++;

    for (i = 0; i < width; i++) {
        vga_buffer[vga_index] = GetBoxDrawChar(topbottom_ch, fore_color, back_color);
        vga_index++;
    }

    vga_buffer[vga_index] = GetBoxDrawChar(bottomright_ch, fore_color, back_color);

    vga_index = 0;
}

void DrawBox(Ui8 boxtype,
    Ui16 x, Ui16 y,
    Ui16 width, Ui16 height,
    Ui8 fore_color, Ui8 back_color)
{
    switch (boxtype) {
    case BOX_SINGLELINE:
        DrawSimpleBox(x, y, width, height,
            fore_color, back_color,
            218, 196, 191, 179, 192, 217);
        break;

    case BOX_DOUBLELINE:
        DrawSimpleBox(x, y, width, height,
            fore_color, back_color,
            201, 205, 187, 186, 200, 188);
        break;
    }
}

void FillBox(Ui8 ch,
    Ui16 x, Ui16 y,
    Ui16 width, Ui16 height,
    Ui8 color)
{
    Ui32 i, j;

    for (i = 0; i < height; i++) {
        vga_index = 80 * y;
        vga_index += x;

        for (j = 0; j < width; j++) {
            vga_buffer[vga_index] = GetBoxDrawChar(ch, 0, color);
            vga_index++;
        }
        y++;
    }
}

#endif
//End of funcs.h