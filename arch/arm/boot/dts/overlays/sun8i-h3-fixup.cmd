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
    fi
done