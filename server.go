package main

import (
	"errors"
	"log/slog"
	"net/http"

	"github.com/labstack/echo/v4"
	"github.com/labstack/echo/v4/middleware"
)

func main() {
	// Echo instance
	e := echo.New()

	// Middleware
	e.Use(middleware.Logger())
	e.Use(middleware.Recover())

	// Routes
	e.GET("/", index)
	e.POST("0.0.0.0:7600/api/swear-filter", func(c echo.Context) error {
		// 요청 처리 로직
		return c.JSON(http.StatusOK, map[string]string{})
	})

	// Start server
	if err := e.Start(":8080"); err != nil && !errors.Is(err, http.ErrServerClosed) {
		slog.Error("failed to start server", "error", err)
	}
}

// Handler
func index(c echo.Context) error {
	return c.File("index.html")
}
