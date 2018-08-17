TARGET   = hammock

CC       = gcc
# compiling flags here
CFLAGS   = -Wall -g

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -lcurl

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
PREFIX = /usr/local


SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f
mkdir	 = mkdir -p


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "link complete"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR) $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiled "$<" successfully"

.PHONY: install
install:
	@$(mkdir) $(DESTDIR)$(PREFIX)/bin
	@cp $(BINDIR)/$(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

.PHONY: uninstall
uninstall:
	@rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) -r $(OBJDIR)

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rm) -r $(OBJDIR)
