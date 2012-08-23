CXX ?= g++
TARGETS =  test_drm_client
PKGS = drm-client
LDFLAGS = `pkg-config --libs $(PKGS)`
CFLAGS = -I. `pkg-config --cflags $(PKGS)`
CFLAGS += -Wall -Wunused-function -Wunreachable-code -ggdb3 -fno-omit-frame-pointer -rdynamic -fno-optimize-sibling-calls -fstack-protector-all

all: $(TARGETS)

$(TARGETS): %: %.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGETS)