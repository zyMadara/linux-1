# overlays fixup script
# Recompile with: mkimage -C none -A arm -T script -d sun8i-h3-fixup.cmd sun8i-h3-fixup.scr


for i in ${overlays}; do 
    if test "${i}" = "uart1"; then
        if test "${uart1/enable}" = "yes"; then
            fdt set /soc/serial@01c28400 status okay
        elif test "${uart1/enable}" = "no"; then
            fdt set /soc/serial@01c28400 status disabled
        fi
    elif test "${i}" = "uart2"; then
        if test "${uart2/enable}" = "yes"; then
            fdt set /soc/serial@01c28800 status okay
        elif test "${uart2/enable}" = "no"; then
            fdt set /soc/serial@01c28800 status disabled
        fi
    elif test "${i}" = "uart3"; then
        if test "${uart3/enable}" = "yes"; then
            fdt set /soc/serial@01c28c00 status okay
        elif test "${uart3/enable}" = "no"; then
            fdt set /soc/serial@01c28c00 status disabled
        fi
    elif test "${i}" = "tft28"; then
        if test "${tft28/enable}" = "yes"; then
            fdt set /soc/spi@01c68000/pitft@0 status okay
            fdt set /soc/spi@01c68000/pitft-ts@1 status okay
        elif test "${tft28/enable}" = "no"; then
            fdt set /soc/spi@01c68000/pitft@0 status disabled
            fdt set /soc/spi@01c68000/pitft-ts@1 status disabled
        fi

        if test -n "${tft28/debug}"; then
            fdt set /soc/spi@01c68000/pitft@0 debug <${tft28/debug}>
        fi

        if test -n "${tft28/speed}"; then
            fdt set /soc/spi@01c68000/pitft@0 spi-max-frequency <${tft28/speed}>
        fi

        if test -n "${tft28/rotate}"; then
            fdt set /soc/spi@01c68000/pitft@0 rotate <${tft28/rotate}>
        fi

        if test -n "${tft28/fps}"; then
            fdt set /soc/spi@01c68000/pitft@0 fps <${tft28/fps}>
        fi
    fi
done